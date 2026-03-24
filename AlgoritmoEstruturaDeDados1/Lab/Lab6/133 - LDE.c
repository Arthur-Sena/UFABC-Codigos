#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int valor;
    struct Node *seguinte;
} Node;

typedef struct LDE
{
    struct Node *cabeca;
} LDE;

void inicializarLista(LDE *lista)
{
    lista->cabeca = NULL;
}

int estaVazia(LDE *lista)
{
    if (lista->cabeca == NULL)
        return 1;
    return 0;
}

int buscar(LDE *lista, int valor)
{
    Node *atual = lista->cabeca;

    while (atual != NULL && atual->valor != valor)
        atual = atual->seguinte;

    if (atual != NULL)
        return valor;

    return -1;
}

void inserir(LDE *lista, int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = valor;

    Node *atual = lista->cabeca;
    Node *anterior = NULL;

    // Percorre a lista para encontrar a posição correta
    while (atual != NULL && atual->valor < valor)
    {
        anterior = atual;
        atual = atual->seguinte;
    }

    if (atual != NULL && atual->valor == valor)
    {
        free(novo);
        return;
    }

    // Insere o novo nó entre anterior e atual
    if (anterior != NULL)
    {
        novo->seguinte = atual;
        anterior->seguinte = novo;
    }
    // Caso o novo nó deva ser inserido no início
    else
    {
        novo->seguinte = lista->cabeca;
        lista->cabeca = novo;
    }
}

void remover(LDE *lista, int valor)
{
    Node *atual = lista->cabeca;
    Node *anterior = NULL;

    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;
        atual = atual->seguinte;
    }

    if (atual == NULL)
        return;

    if (anterior == NULL)
        lista->cabeca = atual->seguinte;
    else
        anterior->seguinte = atual->seguinte;

    free(atual);
}

void imprimir(LDE *lista)
{
    Node *atual = lista->cabeca;

    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->seguinte != NULL ? " " : "\n");
        atual = atual->seguinte;
    }
}

int contem(char *lista, char c)
{
    for (int i = 0; i < strlen(lista); i++)
        if (lista[i] == c)
            return 1;
    return 0;
}

int main()
{
    LDE lista;
    inicializarLista(&lista);

    char op;
    int valor;
    while (scanf("\n%c", &op) != EOF)
    {
        if (contem("IBR", op))
            scanf(" %d", &valor);

        switch (op)
        {
        case 'I':
            inserir(&lista, valor);
            break;

        case 'B':
            buscar(&lista, valor) != -1 ? printf("SIM\n") : printf("NAO\n");
            break;

        case 'R':
            remover(&lista, valor);
            break;

        case 'L':
            imprimir(&lista);
            break;
        }
    }

    return 0;
}