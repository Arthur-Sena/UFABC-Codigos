#include <stdio.h>

typedef struct
{
    int numero;
    char nome[45];
    char equipe[45];
} Piloto;

typedef struct
{
    float tempo;
    int indice;
} Tempo;

void merge(Tempo tempos[], int esquerda, int meio, int direita)
{
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    Tempo E[n1], D[n2];

    for (int i = 0; i < n1; i++)
        E[i] = tempos[esquerda + i];
    for (int j = 0; j < n2; j++)
        D[j] = tempos[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2)
        if (E[i].tempo <= D[j].tempo)
            tempos[k++] = E[i++];
        else
            tempos[k++] = D[j++];

    while (i < n1)
        tempos[k++] = E[i++];

    while (j < n2)
        tempos[k++] = D[j++];
    
}

void mergeSort(Tempo tempos[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int m = esquerda + (direita - esquerda) / 2;

        mergeSort(tempos, esquerda, m);
        mergeSort(tempos, m + 1, direita);

        merge(tempos, esquerda, m, direita);
    }
}

int main()
{
    int quantidade;

    scanf("%d", &quantidade);
    Piloto pilotos[quantidade];
    Tempo tempos[quantidade];

    for (int i = 0; i < quantidade; i++)
        tempos[i].indice = i;

    for (int i = 0; i < quantidade; i++)
        scanf("%d %s %s %f",
              &pilotos[i].numero,
              pilotos[i].nome,
              pilotos[i].equipe,
              &tempos[i].tempo);

    mergeSort(tempos, 0, quantidade - 1);

    int p;
    scanf("%d", &p);
    p = tempos[p - 1].indice;

    printf("%d %s %s\n",
           pilotos[p].numero,
           pilotos[p].nome,
           pilotos[p].equipe);

    return 0;
}