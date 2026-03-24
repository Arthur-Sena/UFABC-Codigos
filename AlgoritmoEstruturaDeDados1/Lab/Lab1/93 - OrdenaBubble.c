#include <stdio.h>

void imprimeVetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", vetor[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    int vetor[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &vetor[i]);

    imprimeVetor(vetor, N);

    int trocas = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocas++;
                imprimeVetor(vetor, N);
            }
        }
    }

    imprimeVetor(vetor, N);
    printf("Trocas: %d\n", trocas);

    return 0;
}