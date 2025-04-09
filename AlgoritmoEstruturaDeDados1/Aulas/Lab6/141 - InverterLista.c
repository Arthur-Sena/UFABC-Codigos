#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int valor;
    struct Node *seguinte;
} Node;

void inicializarNode(Node *novo, int valor)
{
    novo->valor = valor;
    novo->seguinte = NULL;
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

Node *removerNaPosicao(Node *cabeca, int posicao)
{
    if (cabeca == NULL)
    {
        return NULL;
    }

    if (posicao == 0)
    {
        cabeca = cabeca->seguinte;
        return cabeca;
    }

    Node *anterior = NULL;
    Node *atual = cabeca;
    int i = 0;

    while (atual != NULL && i < posicao)
    {
        anterior = atual;
        atual = atual->seguinte;
        i++;
    }

    if (atual == NULL)
    {
        return cabeca;
    }

    anterior->seguinte = atual->seguinte;
    free(atual);

    return cabeca;
}

Node *limparLista(Node *cabeca)
{
    Node *atual = cabeca;
    Node *proximo;

    while (atual != NULL)
    {
        proximo = atual->seguinte;
        free(atual);
        atual = proximo;
    }

    return NULL;
}

int getNode(Node *cabeca, int posicao)
{
    int i = 0;
    Node *atual = cabeca;
    while (atual->seguinte != NULL)
    {
        atual = atual->seguinte;
        i++;
    }

    posicao = i - posicao;

    atual = cabeca;

    for (int j = 0; j < posicao; j++)
    {
        atual = atual->seguinte;
    }

    return atual->valor;
}

void imprimirLista(Node *cabeca)
{
    Node *atual = cabeca;

    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->seguinte != NULL ? " " : "\n"); 
        atual = atual->seguinte;
    }
}

void imprimirPorLinha(Node *cabeca)
{
    Node *atual = cabeca;

    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        atual = atual->seguinte;
    }
}

void imprimirPorLinhaReverso(Node *cabeca)
{
    Node *atual = cabeca;

    if (atual->seguinte != NULL)
        imprimirPorLinhaReverso(atual->seguinte);

    printf("%d\n", atual->valor);
}

Node *inverterLista(Node *cabeca)
{
    Node *anterior = NULL;
    Node *atual = cabeca;
    Node *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->seguinte;
        atual->seguinte = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior;
}

int main()
{
    Node *cabeca = NULL;

    int quantidade, tamanho, valor;

    scanf("%d", &quantidade);

    for (int j = 0; j < quantidade; j++)
    {
        scanf("\n%d", &tamanho);
        if (tamanho < 1)
            continue;

        for (int i = 0; i < tamanho; i++)
        {
            scanf("%d", &valor);
            cabeca = inserirNaPosicao(cabeca, valor, i);
        }

        cabeca = inverterLista(cabeca);

        imprimirLista(cabeca);

        cabeca = limparLista(cabeca);
    }

    return 0;
}