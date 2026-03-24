#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long int *itens;
    int tamanho;
    int inicio;
    int fim;
} Fila;

void inicializar(Fila *fila, int n)
{
    fila->itens = (long int *)malloc(n * sizeof(long int));
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

void inserir(Fila *fila, long int n)
{
    if (!filaCheia(fila))
    {
        fila->itens[fila->fim] = n;
        
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
        printf("%ld%s", fila->itens[i], (i + 1) % fila->tamanho != fila->fim ? " " : "\n");
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    Fila fila;
    inicializar(&fila, N);

    char op;
    long int valor;
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf(" %ld", &valor);
            inserir(&fila, valor);
            break;

        case 'D':
            if (!filaVazia(&fila))
                printf("%ld\n", fila.itens[fila.inicio]);
            remover(&fila);
            break;

        case 'M':
            imprimir(&fila);
            break;
        }
    }

    return 0;
}