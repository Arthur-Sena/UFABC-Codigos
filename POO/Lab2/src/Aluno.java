public class Aluno extends Pessoa {

    //private String nome ;
    private long RA;

    public Aluno(String nomeAluno) {
        //nome = nomeAluno;
        super(nomeAluno);
    }

    public void AtribuirRA(long ra) {
        RA = ra;
    }

    public void Imprimir(String prefixo) {
        System.out.printf("%s%s (RA %d)\n", prefixo, nome, RA);
    }
}