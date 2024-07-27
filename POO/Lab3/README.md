# Utilizando como base o código da atividade anterior (Lab 2)
 
## Modifique:

### Classe Pessoa:
No construtor, faça a seguinte verificação: nome.trim().equals(""). Caso a condição anterior seja verdadeira, enviar uma exceção do tipo Exception com o argumento "nome = ''".
No método abstrato Imprimir, indique que o método pode enviar a exceção Exception.

### Classe Aluno:
Como o construtor de Pessoa envia uma exceção tipo Exception, sinalize que o método repassa essa exceção.
No método AtribuirRA, envia uma exceção tipo IllegalArgumentException com o argumento "RA <= 0". Se o valor do RA for menor ou igual a zero.
No método Imprimir, envie uma exceção do tipo Exception com o argumento "RA <= 0" se o RA for menor ou igual a zero.

### Classe Professor:
Como o construtor de Pessoa envia uma exceção tipo Exception, sinalize que o método repassa essa exceção.
No método AtribuirSIAPE, envia uma exceção tipo IllegalArgumentException com o argumento "SIAPE <= 0". Se o valor do SIAPE for menor ou igual a zero.
No método Imprimir, envie uma exceção do tipo Exception com o argumento "SIAPE <= 0" se o SIAPE for menor ou igual a zero.

### Classe Curso
No método Incluir, envie uma exceção tipo NullPointerException com o argumento "disciplina = null" se o argumento disciplina for nulo.
No método Imprimir, insira um try encapsulando todos os comandos existentes no método, e capture a exceção do tipo Exception e imprima a mensagem de exceção (use o método e.getMessage() para obter a mensagem) no caso de ocorrencia.

## Classe Dicisplina
No método IncluirAluno, adicione uma exceção tipo NullPointerException com o argumento "aluno = null" se o argumento aluno for nulo.
