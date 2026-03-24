#include <stdio.h>

void imprimeVetor(int vetor[], int inicio, int fim)
{
    for (int i = inicio; i <= fim; i++)
    {
        if (i > inicio)
            printf(" ");
        printf("%d", vetor[i]);
    }
    printf("\n");
}

void buscaBinaria(int vetor[], int N, int valor)
{
    int esquerda = 0;
    int direita = N - 1;
    int encontrado = 0;

    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;

        if (vetor[meio] == valor)
        {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", valor);
            encontrado = 1;
            break;
        }
        else if (vetor[meio] < valor)
        {
            imprimeVetor(vetor, esquerda, meio);
            esquerda = meio + 1;
        }
        else
        {
            imprimeVetor(vetor, meio, direita);
            direita = meio - 1;
        }
    }

    if (!encontrado)
        printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", valor);
}

int main()
{
    int N;
    scanf("%d", &N);

    int vetor[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int valor;
    while (scanf("%d", &valor) != EOF)
    {
        buscaBinaria(vetor, N, valor);
    }

    return 0;
}