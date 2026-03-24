#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_STRING 100

typedef struct
{
    char (*itens)[TAMANHO_STRING];
    int tamanho;
    int inicio;
    int fim;
} Fila;

void inicializar(Fila *fila, int n)
{
    fila->itens = (char (*)[TAMANHO_STRING])malloc(n * sizeof(char[TAMANHO_STRING]));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = n;
}

int filaCheia(Fila *fila)
{
    return (fila->fim + 1) % fila->tamanho == fila->inicio;
}

int filaVazia(Fila *fila)
{
    return fila->fim == fila->inicio;
}

void inserir(Fila *fila, char palavra[])
{
    if (!filaCheia(fila))
    {
        strcpy(fila->itens[fila->fim], palavra);
        
        fila->fim = (fila->fim + 1) % fila->tamanho;
    }
}

void remover(Fila *fila)
{
    if (!filaVazia(fila))
    {
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
    }
}

void imprimir(Fila *fila)
{
    for (int i = fila->inicio; i != fila->fim; i = (i + 1) % fila->tamanho)
    {
        printf("%s%s", fila->itens[i], (i + 1) % fila->tamanho != fila->fim ? " " : "\n");
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    Fila fila;
    inicializar(&fila, N);

    char op;
    char palavra[TAMANHO_STRING];
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf(" %s", palavra);
            inserir(&fila, palavra);
            break;

        case 'D':
            if (!filaVazia(&fila))
                printf("%s\n", fila.itens[fila.inicio]);
            remover(&fila);
            break;

        case 'M':
            imprimir(&fila);
            break;
        }
    }

    return 0;
}