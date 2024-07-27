public class Aluno extends Pessoa {

    //private String nome ;
    private long RA;

    public Aluno(String nomeAluno) throws Exception{
        //nome = nomeAluno;
        super(nomeAluno);
    }

    public void AtribuirRA(long ra) {
        if (ra <= 0)
            throw new IllegalArgumentException ("RA <= 0");

        RA = ra;
    }

    public void Imprimir(String prefixo) throws Exception{
        if (this.RA <= 0)
            throw new Exception("RA <= 0");

        System.out.printf("%s%s (RA %d)[%d]\n", prefixo, nome, RA, id);
    }
}