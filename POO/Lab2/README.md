# Utilizando como base o código da atividade anterior (Lab 1)
 
## Modifique:

### Classe Pessoa:

Inclua uma variável privado e estático chamado id_counter tipo long.
Inclua uma variável protegido id tipo long.
No construtor, incremente id_counter para cada instância e atribua para id. A primeira instância deve ter o id igual a 1, sendo incrementado um a a um.

### Classe Aluno:

Modifique a função Imprimir para:
```
    public void Imprimir(String prefixo) {
        System.out.printf("%s%s (RA %d)[%d]\n", prefixo, nome, RA, id);
    }
```
### Classe Professor:

Modifique a função imprimir para:
```
    public void Imprimir(String prefixo) {
        System.out.printf("%s%s (SIAPE %d)[%d]\n", prefixo, nome, siape, id);
    }
```

### Classe Curso

Inclua um atributo público e estático chamado universidade tipo String com valor inicial igual a "UFABC".
Adicione um método estático chamado gerarCodigoDisciplina que recebe nomeDisciplina (tipo String) e retorne uma String com o seguinte formato:
    ```return universidade + "_" + nomeDisciplina;```
Adicione na primeira linha de Imprimir o seguinte comando:
  ```
    System.out.printf("%s\n", universidade);
  ```

### Classe Dicisplina

Altere a primeira linha do método Imprimir para o seguinte comando:
```
    System.out.printf("%s%s [%s]\n", prefixo, nome, Curso.gerarCodigoDisciplina(nome));
```
