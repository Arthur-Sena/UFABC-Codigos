# projeto-final

## Aluno: Eduardo C. Ferreira RA: 11019314

### Projeto Final para a matéria Paradigmas de Programação (MCTA016-13) da UFABC - Quadrimestre Suplementar de 2020.

 Neste projeto foi realizado a implementação de um jogo de xadrez na linguagem Haskell. A interface utilizada é através do GNOME Terminal. Existem 3 possibilidades de jogo:
 
  - Jogo Local: Dois jogadores utilizarem o mesmo terminal para jogar uma partida.
  - Rede : Um jogador atua como host esperando a conexão de outro jogador, e assim que ambos se conectam a partida dá início.
  - Solo : Um jogador se conecta a um servidor utilizando uma IA como adversário. Assim que o jogador se conecta a partida dá inicio.
  
Para isto existem 4 executáveis:

 - local : Abre o jogo para duas pessoas no mesmo terminal.
 - host : Abre o jogo que aguarda uma conexão. Para jogar versus outro jogador.
 - client <IP> : Executa passando como argumento o IP do host desejado, e caso exista abre uma partida versus contra o host, podendo ser outro jogador ou uma IA.
 - hostIA : Abre o jogo que aguarda uma conexão. Neste caso é possível vários jogadores se conectarem neste host. Os clientes então jogam uma partida contra uma IA.
 
 Obs. A IA implementada neste caso toma uma decisão aleatória, sem nenhuma análise da partida.

Link apresentação: https://youtu.be/l5D02mKKOsg
