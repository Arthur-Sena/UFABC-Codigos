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
void inicializarNode(Node *novo, int valor)
{
    novo->valor = valor;
    novo->seguinte = NULL;
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

void inserirCabeca(Node *cabeca, int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));

    novo->valor = cabeca->valor;
    novo->seguinte = cabeca->seguinte;
    cabeca->valor = valor;
    cabeca->seguinte = novo;
}

void inserirCalda(Node *cabeca, int valor)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    inicializarNode(novo, valor);

    Node *atual = cabeca;

    while (atual->seguinte != NULL)
        atual = atual->seguinte;

    atual->seguinte = novo;
}

Node *inserirNaPosicao(Node *cabeca, int valor, int posicao)
{

    Node *novo = (Node *)malloc(sizeof(Node));
    inicializarNode(novo, valor);

    if (cabeca == NULL)
    {
        cabeca = novo;
        return cabeca;
    }

    Node *atual = cabeca;
    Node *anterior = NULL;

    int i = 0;
    while (atual != NULL && i < posicao)
    {
        anterior = atual;
        atual = atual->seguinte;
        i++;
    }

    if (anterior != NULL)
    {
        novo->seguinte = atual;
        anterior->seguinte = novo;
    }
    else
    {
        novo->seguinte = cabeca;
        cabeca = novo;
    }

    return cabeca;
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
        inicializarNode(novo, valor);
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

void limparLista(LDE *lista)
{
    Node *atual = lista->cabeca;
    Node *proximo;

    while (atual != NULL)
    {
        proximo = atual->seguinte;
        free(atual);
        atual = proximo;
    }

    lista->cabeca = NULL;
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

int main()
{
    LDE lista;
    inicializarLista(&lista);

    int tamanho, valor, posicao;

    scanf("%d", &tamanho);

    int i = 0;
    for (i; i < tamanho; i++)
    {
        scanf("\n%d %d", &valor, &posicao);

        lista.cabeca = inserirNaPosicao(lista.cabeca, valor, posicao);
    }
    imprimir(&lista);

    limparLista(&lista);

    return 0;
}