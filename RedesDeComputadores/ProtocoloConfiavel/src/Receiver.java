// Arthur Sena - 1120223175
import java.io.*;
import java.net.*;
import java.util.*;

public class Receiver {
    private static final int PORTA_PADRAO = 9876;
    
    // Funcionalidade: Implementar o buffer de pacotes (recebidos) no receiver.
    // Usamos um TreeMap para manter os pacotes fora de ordem organizados pelo ID.
    private static Map<Integer, SegmentoConfiavel> buffer = new TreeMap<>();
    private static int expectedId = 0; // Próximo pacote esperado na ordem correta

    public static void main(String[] args) {
        try {
            // Inicialização da captura/leitura de IP e porta do receiver.
            BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Digite a porta para o Receiver escutar (Enter para " + PORTA_PADRAO + "): ");
            String portaStr = teclado.readLine();
            int porta = portaStr.isEmpty() ? PORTA_PADRAO : Integer.parseInt(portaStr);

            DatagramSocket socket = new DatagramSocket(porta);
            System.out.println("Receiver aguardando mensagens na porta " + porta + "...\n");

            byte[] receiveData = new byte[1024];

            while (true) {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                socket.receive(receivePacket);

                SegmentoConfiavel segmentoRecebido = (SegmentoConfiavel) desserializar(receivePacket.getData());

                if (segmentoRecebido.isAck()) continue; // Receiver não processa ACKs

                int id = segmentoRecebido.getId();
                
                // Funcionalidade: Envio do reconhecimento (ACK)
                enviarAck(socket, receivePacket.getAddress(), receivePacket.getPort(), id);

                // Funcionalidade: Implementar o tratamento de pacotes duplicados.
                if (id < expectedId || buffer.containsKey(id)) {
                    System.out.println("Mensagem id " + id + " recebida de forma duplicada");
                } 
                // Funcionalidade: Pacote recebido na ordem correta
                else if (id == expectedId) {
                    System.out.println("Mensagem id " + id + " recebida na ordem, entregando para a camada de aplicação.");
                    expectedId++;

                    // Verifica se o buffer possui os próximos pacotes da sequência (Selective Repeat)
                    while (buffer.containsKey(expectedId)) {
                        buffer.remove(expectedId);
                        System.out.println("Mensagem id " + expectedId + " recebida na ordem, entregando para a camada de aplicação.");
                        expectedId++;
                    }
                } 
                // Funcionalidade: Implementar o tratamento de pacotes fora de ordem.
                else if (id > expectedId) {
                    buffer.put(id, segmentoRecebido); // Coloca no buffer

                    List<Integer> missing = new ArrayList<>();
                    for (int i = expectedId; i < id; i++) {
                        if (!buffer.containsKey(i)) {
                            missing.add(i);
                        }
                    }
                    System.out.println("Mensagem id " + id + " recebida fora de ordem, ainda não recebidos os identificadores " + missing.toString());
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void enviarAck(DatagramSocket socket, InetAddress ipAcesso, int portaAcesso, int id) throws Exception {
        SegmentoConfiavel ack = new SegmentoConfiavel(id, "ACK", true);
        byte[] sendData = serializar(ack);
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, ipAcesso, portaAcesso);
        socket.send(sendPacket);
    }

    private static Object desserializar(byte[] bytes) throws Exception {
        ByteArrayInputStream bais = new ByteArrayInputStream(bytes);
        ObjectInputStream ois = new ObjectInputStream(bais);
        return ois.readObject();
    }
    
    private static byte[] serializar(Object obj) throws Exception {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oos = new ObjectOutputStream(baos);
        oos.writeObject(obj);
        return baos.toByteArray();
    }
}