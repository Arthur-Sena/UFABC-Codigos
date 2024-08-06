import java.util.ArrayList;

public class Produtor {
    // Lista com todas as instâncias de Produzir (cada uma rodando em uma Thread)
    private ArrayList<Produzir> produtores = new ArrayList<Produzir>();

    // Construtor, jah implementado... nao alterar!
    Produtor(String nome, int total_de_itens, int tempo_de_producao, int num_threads) {
        int itens_por_thread = total_de_itens / num_threads;
        int thread_com_1_item_adicional = total_de_itens % num_threads;
        for (int t = 0; t < num_threads; t++) {
            final int itens_para_produzir = itens_por_thread + (t < thread_com_1_item_adicional ? 1 : 0);
            Produzir p = new Produzir(nome + Main.separadorIdSequencial + String.valueOf(t+1), itens_para_produzir, tempo_de_producao);
            produtores.add(p);
        }
    }

    public void produzir() {
        // IMPLEMENTAR!!!
        // Executar (chamar .start()) para cada Thread (classe Produzir)
        for (Produzir produtor : produtores) {
            produtor.start();
        }
    };

    public class Produzir extends Thread {
        private String nome;
        private int total_itens;
        private int tempo_producao;

        Produzir(String nome, int qtd, int ms) {
            super(nome);
            this.total_itens = qtd;
            this.tempo_producao = ms;
        }

        @Override
        public void run() {
            for (int i = 0; i < total_itens; i++) {
                // Simulando o tempo de producao...
                try {
                    sleep(tempo_producao);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                // IMPLEMENTAR!!!
                // Chamar Fila.instancia().inserir(getName());
                // Nao esquecer de protegar esta regiao critica!
                synchronized(Fila.instancia()) {
                    Fila.instancia().inserir(getName());
                }
            }
        }
    }
}