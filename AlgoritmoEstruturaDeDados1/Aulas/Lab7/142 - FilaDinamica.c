#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    int valor;
    struct Item *proximo;
};

struct FilaDinamica
{
    struct Item *inicio;
    struct Item *fim;
    int tamanho;
};

struct FilaDinamica *criarFila()
{
    struct FilaDinamica *fila = (struct FilaDinamica *)malloc(sizeof(struct FilaDinamica));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

int filaVazia(struct FilaDinamica *fila)
{
    return fila->inicio == NULL;
}

void enfileirar(struct FilaDinamica *fila, int valor)
{
    struct Item *novo = (struct Item *)malloc(sizeof(struct Item));
    novo->valor = valor;
    novo->proximo = NULL;

    if (filaVazia(fila))
        fila->inicio = novo;
    else
        fila->fim->proximo = novo;

    fila->fim = novo;
    fila->tamanho++;
}

void desenfileirar(struct FilaDinamica *fila)
{
    if (filaVazia(fila))
        return;

    struct Item *remover = fila->inicio;

    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    fila->tamanho--;
    printf("<%d>\n", remover->valor);
    free(remover);
}

void mostrarFila(struct FilaDinamica *fila)
{
    struct Item *atual = fila->inicio;
    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "\n");
        atual = atual->proximo;
    }
}

int main()
{
    struct FilaDinamica *fila = criarFila();

    char opc;
    int valor;

    while (scanf("\n%c", &opc) != EOF)
    {
        switch (opc)
        {
        case 'E':
            scanf(" %d", &valor);
            enfileirar(fila, valor);
            break;
        case 'D':
            desenfileirar(fila);
            break;
        case 'M':
            mostrarFila(fila);
            break;
        }
    }

    return 0;
}
