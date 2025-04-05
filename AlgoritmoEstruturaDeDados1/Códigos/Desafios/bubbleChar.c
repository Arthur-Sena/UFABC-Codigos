#include <stdio.h>
#include <stdlib.h>

void preencheLista(char* vetor, int qntElementos);
int ordenaBubbleSort(char* vetor, int qntComparacoes, int qntElementos);
void imprimeVetorAtual(char* vetor, int qntElementos);

int main()
{
    int totalTrocas = 0, qntElementos;
    scanf("%d", &qntElementos);

    char* vetor = (char*) malloc(qntElementos * sizeof(char));
    preencheLista(vetor, qntElementos);

    for (int i = qntElementos - 1; i > 0; i--)
        totalTrocas += ordenaBubbleSort(vetor, i, qntElementos);

    imprimeVetorAtual(vetor, qntElementos);
    printf("Trocas: %d\n", totalTrocas);
    return 0;
}

void preencheLista(char* vetor, int qntElementos)
{
    for(int i = 0; i < qntElementos; i++)
        scanf(" %c", &vetor[i]);// " %c" para não ler espaços em branco e quebra de linha
    imprimeVetorAtual(vetor, qntElementos);
}

void imprimeVetorAtual(char* vetor, int qntElementos)
{
    for (int i = 0; i < qntElementos; i++)
        if (i == qntElementos - 1)    
            printf("%c\n", vetor[i]);
        else
            printf("%c ", vetor[i]);
}

int ordenaBubbleSort(char* vetor, int qntComparacoes, int qntElementos)
{
    int qntTrocas = 0;
    for (int idAvaliado = 0; idAvaliado < qntComparacoes; idAvaliado++)
        if (vetor[idAvaliado] > vetor[idAvaliado + 1])
        {
            char temp = vetor[idAvaliado];
            vetor[idAvaliado] = vetor[idAvaliado + 1];
            vetor[idAvaliado + 1] = temp;
            qntTrocas++;
            imprimeVetorAtual(vetor, qntElementos);
        }

    return qntTrocas;
}