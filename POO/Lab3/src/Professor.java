public class Professor extends Pessoa{

    //private String nome ;
    private long siape;

    public Professor(String nome) throws Exception{
        //nome = nomeProfessor;
        super(nome);
    }

    public void AtribuirSIAPE (long siape) {
        if (siape <= 0)
            throw new IllegalArgumentException("SIAPE <= 0");

        this.siape = siape;
    }

    public void Imprimir(String prefixo) throws Exception{
        if (this.siape <= 0){
            throw new Exception("SIAPE <= 0");
        }

        System.out.printf("%s%s (SIAPE %d)[%d]\n", prefixo, nome, siape, id);
    }
}