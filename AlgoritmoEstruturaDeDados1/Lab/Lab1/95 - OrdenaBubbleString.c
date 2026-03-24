#include <stdio.h>
#include <string.h>

void imprimeVetor(char vetor[][100], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%s", vetor[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    char vetor[N][100];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", vetor[i]);
    }

    imprimeVetor(vetor, N);

    int trocas = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (strcmp(vetor[j], vetor[j + 1]) > 0)
            {
                char temp[100];
                strcpy(temp, vetor[j]);
                strcpy(vetor[j], vetor[j + 1]);
                strcpy(vetor[j + 1], temp);
                trocas++;
                imprimeVetor(vetor, N);
            }
        }
    }

    imprimeVetor(vetor, N);

    printf("Trocas: %d\n", trocas);

    return 0;
}