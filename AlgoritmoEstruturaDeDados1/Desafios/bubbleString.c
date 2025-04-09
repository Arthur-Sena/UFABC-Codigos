#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencheLista(char **vetor, int qntElementos);
int ordenaBubbleSort(char **vetor, int qntComparacoes, int qntElementos);
void imprimeVetorAtual(char **vetor, int qntElementos);

int main()
{
    int totalTrocas = 0, qntElementos;
    scanf("%d", &qntElementos);

    char **vetor = (char **) malloc(qntElementos * sizeof(char *));
    for (int i = 0; i < qntElementos; i++)
        vetor[i] = (char *) malloc(100 * sizeof(char)); 

    preencheLista(vetor, qntElementos);

    for (int i = qntElementos - 1; i > 0; i--)
        totalTrocas += ordenaBubbleSort(vetor, i, qntElementos);

    imprimeVetorAtual(vetor, qntElementos);
    printf("Trocas: %d\n", totalTrocas);

    for (int i = 0; i < qntElementos; i++) 
        free(vetor[i]);
    
    free(vetor);
    return 0;
}

void preencheLista(char **vetor, int qntElementos)
{
    for (int i = 0; i < qntElementos; i++) {
        scanf("%s", vetor[i]); // Lê uma string
    }
    imprimeVetorAtual(vetor, qntElementos);
}

void imprimeVetorAtual(char **vetor, int qntElementos)
{
    for (int i = 0; i < qntElementos; i++) {
        if (i == qntElementos - 1)
            printf("%s\n", vetor[i]);
        else
            printf("%s ", vetor[i]);
    }
}

int ordenaBubbleSort(char **vetor, int qntComparacoes, int qntElementos)
{
    int qntTrocas = 0;
    for (int idAvaliado = 0; idAvaliado < qntComparacoes; idAvaliado++) {
        if (strcmp(vetor[idAvaliado], vetor[idAvaliado + 1]) > 0) {
            char *temp = vetor[idAvaliado];
            vetor[idAvaliado] = vetor[idAvaliado + 1];
            vetor[idAvaliado + 1] = temp;
            qntTrocas++;
            imprimeVetorAtual(vetor, qntElementos);
        }
    }
    return qntTrocas;
}