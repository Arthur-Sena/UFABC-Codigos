#include <stdio.h>
#include <stdlib.h>

void preencheLista(int* vetor, int qntElementos);
int ordenaBubbleSort(int* vetor, int qntComparacoes, int qntElementos);
void imprimeVetorAtual(int* vetor, int qntElementos);

int main()
{
    int totalTrocas = 0, qntElementos;
    scanf("%d", &qntElementos);

    int* vetor = (int*) malloc(qntElementos * sizeof(int));
    preencheLista(vetor, qntElementos);

    for (int i = qntElementos - 1; i > 0; i--)
        totalTrocas += ordenaBubbleSort(vetor, i, qntElementos);

    imprimeVetorAtual(vetor, qntElementos);
    printf("Trocas: %d\n", totalTrocas);
    return 0;
}

void preencheLista(int* vetor, int qntElementos)
{
    for(int i = 0; i < qntElementos; i++)
        scanf("%d", &vetor[i]);
    imprimeVetorAtual(vetor, qntElementos);
}

void imprimeVetorAtual(int* vetor, int qntElementos)
{
    for (int i = 0; i < qntElementos; i++)
        if (i == qntElementos - 1)    
            printf("%d\n", vetor[i]);
        else
            printf("%d ", vetor[i]);
}

int ordenaBubbleSort(int* vetor, int qntComparacoes, int qntElementos)
{
    int qntTrocas = 0;
    for (int idAvaliado = 0; idAvaliado <= qntComparacoes; idAvaliado++)
        if (vetor[idAvaliado] > vetor[idAvaliado + 1])
        {
            int saveNum = vetor[idAvaliado];
            vetor[idAvaliado] = vetor[idAvaliado + 1];
            vetor[idAvaliado + 1] = saveNum;
            qntTrocas++;
            imprimeVetorAtual(vetor, qntElementos);
        }

    return qntTrocas;
}