import java.util.ArrayList;

public class Consumidor {
    // Lista com todas as instâncias de Consumir (cada uma rodando em uma Thread)
    private ArrayList<Consumir> consumidores = new ArrayList<Consumir>();

    // Construtor, jah implementado... nao alterar!
    Consumidor(String nome, int total_de_itens, int tempo_de_producao, int num_threads) {
        int itens_por_thread = total_de_itens / num_threads;
        int thread_com_1_item_adicional = total_de_itens % num_threads;
        for (int t = 0; t < num_threads; t++) {
            final int itens_para_consumir = itens_por_thread + (t < thread_com_1_item_adicional ? 1 : 0);
            Consumir c = new Consumir(nome + Main.separadorIdSequencial + String.valueOf(t+1), itens_para_consumir, tempo_de_producao);
            consumidores.add(c);
        }
    }

    public void consumir() {
        // IMPLEMENTAR!!!
        // Executar (chamar .start()) para cada Thread (classe Consumir)
        for (Consumir consumidor : consumidores) {
            consumidor.start();
        }
    };

    public class Consumir extends Thread {
        private String nome;
        private int total_itens;
        private int tempo_producao;

        Consumir(String nome, int qtd, int ms) {
            super(nome);
            this.total_itens = qtd;
            this.tempo_producao = ms;
        }

        @Override
        public void run() {
            for (int i = 0; i < total_itens; i++) {

                // IMPLEMENTAR!!!
                // Chamar Fila.instancia().remover(getName());
                // Nao esquecer de protegar esta regiao critica!
                synchronized(Fila.instancia()) {
                    Fila.instancia().remover(getName());
                }

                // Simulando o tempo de consumo...
                try {
                    sleep(tempo_producao);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
