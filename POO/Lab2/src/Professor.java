public class Professor extends Pessoa {

    //private String nome ;
    private long siape;

    public Professor(String nome) {
        //nome = nomeProfessor;
        super(nome);
    }

    public void AtribuirSIAPE (long siape) {
        this.siape = siape;
    }

    public void Imprimir(String prefixo) {
        System.out.printf("%s%s (SIAPE %d)\n", prefixo, nome, siape);
    }
}