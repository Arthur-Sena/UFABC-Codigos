import java.util.ArrayList;

public class Curso {

    private String nome;
    private ArrayList<Disciplina> disciplinas;
    public static String universidade = "UFABC";

    public Curso(String nome) {
        disciplinas = new ArrayList<Disciplina>();
        this.nome = nome;
    }

    public void Incluir(Disciplina disciplina) {
        this.disciplinas.add(disciplina);
    }

    public void Imprimir() {
        System.out.printf("%s\n", universidade);
        System.out.printf("Curso de %s:\n", nome);
        System.out.println("\tDisciplinas:");
        if (disciplinas.size() > 0) {
            for (Disciplina d: disciplinas) {
                d.Imprimir("\t\t");
            }
        } else {
            System.out.println("\t\t-vazio-");
        }
    }

    public static String gerarCodigoDisciplina(String nomeDisciplina){
        return universidade + "_" + nomeDisciplina;
    }
}