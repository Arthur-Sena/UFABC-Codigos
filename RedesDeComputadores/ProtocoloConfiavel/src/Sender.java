// Arthur Sena - 1120223175
import java.io.*;
import java.net.*;
import java.util.Map;
import java.util.concurrent.*;

public class Sender {
    private static final int TIMEOUT_MS = 3000;
    
    // Funcionalidade: Implementar o buffer de pacotes (enviados e não ack) no sender.
    private static ConcurrentHashMap<Integer, SegmentoConfiavel> unackedPackets = new ConcurrentHashMap<>();
    private static ConcurrentHashMap<Integer, Long> sentTimes = new ConcurrentHashMap<>();
    
    private static DatagramSocket socket;
    private static InetAddress ipReceiver;
    private static int portaReceiver;
    private static int nextId = 0;
    
    // Usado para simular a opção "fora de ordem"
    private static SegmentoConfiavel heldPacket = null; 

    public static void main(String[] args) {
        try {
            BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));

            // Funcionalidade: Inicialização da captura/leitura de IP e porta. Deixe como default 127.0.0.1
            System.out.print("Digite o IP do Receiver (Enter para 127.0.0.1): ");
            String ipStr = teclado.readLine();
            if (ipStr.isEmpty()) ipStr = "127.0.0.1";
            ipReceiver = InetAddress.getByName(ipStr);

            System.out.print("Digite a porta do Receiver (Enter para 9876): ");
            String portaStr = teclado.readLine();
            portaReceiver = portaStr.isEmpty() ? 9876 : Integer.parseInt(portaStr);

            socket = new DatagramSocket(); // Porta aleatória para o Sender

            // Inicia Threads aninhadas para recebimento de ACKs e verificação de Timeout
            new Thread(new AckReceiver()).start();
            new Thread(new TimeoutChecker()).start();

            while (true) {
                System.out.println("\n--- Nova Mensagem ---");
                System.out.print("Digite a mensagem: \n");
                String msg = teclado.readLine();

                System.out.println("Opções de envio: [1] normal, [2] lenta, [3] perda, [4] fora de ordem, [5] duplicada");
                System.out.print("Escolha a opção: \n");
                String opcao = teclado.readLine();

                int currentId = nextId++;
                SegmentoConfiavel seg = new SegmentoConfiavel(currentId, msg, false);

                switch (opcao) {
                    case "1": // Normal
                        System.out.println("\nMensagem \"" + msg + "\" enviada como normal com id " + currentId);
                        registrarEnvio(seg);
                        enviarFisicamente(seg);
                        
                        // Libera pacote retido para simular "fora de ordem"
                        if (heldPacket != null) {
                            enviarFisicamente(heldPacket);
                            heldPacket = null;
                        }
                        break;

                    case "2": // Lenta
                        System.out.println("\nMensagem \"" + msg + "\" enviada como lenta com id " + currentId);
                        registrarEnvio(seg);
                        // Funcionalidade: Tratamento de pacotes lentos. Thread segura e envia APÓS o timeout.
                        new Thread(() -> {
                            try { Thread.sleep(TIMEOUT_MS + 1000); } catch (InterruptedException e) {}
                            enviarFisicamente(seg);
                        }).start();
                        break;

                    case "3": // Perda
                        System.out.println("\nMensagem \"" + msg + "\" enviada como perda com id " + currentId);
                        registrarEnvio(seg);
                        // Funcionalidade: Tratamento de pacotes perdidos. Não enviamos pela rede fisicamente.
                        break;

                    case "4": // Fora de ordem
                        System.out.println("\nMensagem \"" + msg + "\" enviada como fora de ordem com id " + currentId);
                        registrarEnvio(seg);
                        if (heldPacket != null) enviarFisicamente(heldPacket); // Garante que não trava
                        heldPacket = seg; // Segura o pacote. Será enviado só após o envio do próximo "normal"
                        break;

                    case "5": // Duplicada
                        System.out.println("\nMensagem \"" + msg + "\" enviada como duplicada com id " + currentId);
                        registrarEnvio(seg);
                        enviarFisicamente(seg);
                        enviarFisicamente(seg); // Envia duas vezes em sequência
                        break;

                    default:
                        System.out.println("Opção inválida.");
                        nextId--; // Reverte o ID já que falhou
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void registrarEnvio(SegmentoConfiavel seg) {
        unackedPackets.put(seg.getId(), seg);
        sentTimes.put(seg.getId(), System.currentTimeMillis());
    }

    private static void enviarFisicamente(SegmentoConfiavel seg) {
        try {
            byte[] data = serializar(seg);
            DatagramPacket packet = new DatagramPacket(data, data.length, ipReceiver, portaReceiver);
            socket.send(packet);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Funcionalidade: Implementar o tratamento de pacotes perdidos / lentos (Uso de temporizador e timeout)
    private static class TimeoutChecker implements Runnable {
        public void run() {
            while (true) {
                try {
                    Thread.sleep(500); // Verifica a cada meio segundo
                    long now = System.currentTimeMillis();
                    
                    for (Map.Entry<Integer, Long> entry : sentTimes.entrySet()) {
                        int id = entry.getKey();
                        long time = entry.getValue();
                        
                        if (now - time > TIMEOUT_MS) {
                            System.out.println("Mensagem id " + id + " deu timeout, reenviando.");
                            sentTimes.put(id, now); // Reseta o cronômetro
                            SegmentoConfiavel seg = unackedPackets.get(id);
                            if (seg != null) {
                                enviarFisicamente(seg);
                            }
                        }
                    }
                } catch (InterruptedException e) { break; }
            }
        }
    }

    private static class AckReceiver implements Runnable {
        public void run() {
            byte[] receiveData = new byte[1024];
            while (true) {
                try {
                    DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                    socket.receive(receivePacket);
                    SegmentoConfiavel ack = (SegmentoConfiavel) desserializar(receivePacket.getData());
                    
                    if (ack.isAck()) {
                        int id = ack.getId();
                        if (unackedPackets.containsKey(id)) {
                            unackedPackets.remove(id);
                            sentTimes.remove(id);
                            System.out.println("Mensagem id " + id + " recebida pelo receiver.");
                        }
                    }
                } catch (Exception e) { e.printStackTrace(); }
            }
        }
    }

    private static byte[] serializar(Object obj) throws Exception {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(obj);
        return baos.toByteArray();
    }
    
    private static Object desserializar(byte[] bytes) throws Exception {
        ByteArrayInputStream bais = new ByteArrayInputStream(bytes);
        ObjectInputStream ois = new ObjectInputStream(bais);
        return ois.readObject();
    }
}