#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    char matricula[15];
    char nome[85];
    int exercicios;
    int tempo;
};

void troca(struct Aluno *a, struct Aluno *b)
{
    struct Aluno temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPlacar(struct Aluno *placar, int N)
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)

            if (placar[i].exercicios < placar[j].exercicios)
                troca(&placar[i], &placar[j]);

            else if (placar[i].exercicios == placar[j].exercicios)
                 if (placar[i].tempo > placar[j].tempo)
                    troca(&placar[i], &placar[j]);
}

int main () {

    int N;
    scanf("%d", &N);

    struct Aluno *placar = (struct Aluno *)malloc(N * sizeof(struct Aluno));

    for (int i = 0; i < N; i++)
        scanf("%s %s %d %d", placar[i].matricula, placar[i].nome, &placar[i].exercicios, &placar[i].tempo);

    ordenarPlacar(placar, N);

    for (int i = 0; i < N; i++)
        printf("%s %s %d (%d)\n", placar[i].matricula, placar[i].nome, placar[i].exercicios, placar[i].tempo);

    return 0;
}