#include <stdio.h>

int main()
{
    int direcao = 0;
    char direcoes[] = "NLSO";

    int N;
    scanf("%d", &N);

    char comandos[N+1];
    scanf("%s", comandos);

    for (int i = 0; i < N; i++)
    {
        direcao += (comandos[i] == 'D') ? 1 : 0;
        direcao += (comandos[i] == 'E') ? 3 : 0;
    }
    direcao = direcao % 4;

    printf("%c\n", direcoes[direcao]);

    return 0;
}