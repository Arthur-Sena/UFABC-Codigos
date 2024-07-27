public class Pessoa {

    protected long id;
    private static long id_counter = 0;
    protected String nome ;

    public Pessoa(String nome) throws Exception{

        if (nome.trim().equals(""))
            throw new Exception("nome = ''");

        this.nome = nome;
        id_counter = id_counter + 1;
        id = id_counter;
    }

    public void Imprimir(String prefixo) throws Exception{
        //System.out.printf("%s%s (SIAPE %d)\n", prefixo, nome, siape);
    }
}