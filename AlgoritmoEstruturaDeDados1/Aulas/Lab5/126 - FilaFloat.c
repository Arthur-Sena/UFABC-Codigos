#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float *itens;
    int tamanho;
    int inicio;
    int fim;
} Fila;

void inicializar(Fila *fila, int n)
{
    fila->itens = (float *)malloc(n * sizeof(float));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = n;
}

int filaCheia(Fila *fila)
{
    return fila->fim == fila->tamanho;
}

int filaVazia(Fila *fila)
{
    return fila->fim - fila->inicio == 0;
}

void inserir(Fila *fila, float n)
{
    !filaCheia(fila) ? fila->itens[fila->fim++] = n : 0;
}

int remover(Fila *fila)
{
    !filaVazia(fila) ? fila->inicio++ : 0;

    if (fila->inicio == fila->fim)
    {
        fila->inicio = 0;
        fila->fim = 0;
    }
}

int imprimir(Fila *fila)
{
    for (int i = fila->inicio; i < fila->fim; i++)
        printf("%.2f%s", fila->itens[i], i < fila->fim - 1 ? " " : "\n");
}

int main()
{

    int N;
    scanf("%d", &N);

    Fila fila;
    inicializar(&fila, N);

    char op;
    float valor;
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf(" %f", &valor);
            inserir(&fila, valor);
            break;

        case 'D':
            if (!filaVazia(&fila))
                printf("%.2f\n", fila.itens[fila.inicio]);
            remover(&fila);
            break;

        case 'M':
            imprimir(&fila);
            break;
        }
    }

    return 0;
}