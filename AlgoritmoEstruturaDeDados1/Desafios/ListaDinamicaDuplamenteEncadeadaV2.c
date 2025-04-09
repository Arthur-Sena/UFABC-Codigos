#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item
{
    int valor;
    struct Item *anterior;
    struct Item *proximo;
} Item;

typedef struct Lista
{
    Item *primeiro;
    Item *ultimo;
} Lista;

Lista *criarLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}

void adicionar(Lista *l, int valor)
{
    Item *anterior = NULL, *atual = l->primeiro;

    Item *novo = (Item *)malloc(sizeof(Item));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;

    while (atual != NULL && atual->valor < novo->valor)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && valor == atual->valor)
        return;

    novo->proximo = atual;
    novo->anterior = anterior;
    if (anterior != NULL)
    {
        if (atual != NULL)
            atual->anterior = novo;
        else
            l->ultimo = novo;
        anterior->proximo = novo;
    }
    else
    {
        if (l->primeiro != NULL)
            atual->anterior = novo;
        else
            l->ultimo = novo;
        l->primeiro = novo;
    }
}

void listarInicioFim(Lista *l)
{
    if (l == NULL || l->primeiro == NULL || l->ultimo == NULL)
        return;

    Item *atual = l->primeiro;
    while (atual->proximo != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("%d\n", atual->valor);
}

void listarFimInicio(Lista *l)
{
    if (l == NULL || l->primeiro == NULL || l->ultimo == NULL)
        return;

    Item *atual = l->ultimo;
    while (atual->anterior != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("%d\n", atual->valor);
}

void remover(Lista *l, int valor)
{
    struct Item *anterior = NULL, *atual = l->primeiro;

    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        if (anterior != NULL)
            anterior->proximo = atual->proximo;
        else
            l->primeiro = atual->proximo;

        if (atual != l->ultimo)
            atual->proximo->anterior = anterior;
        else
            l->ultimo = anterior;
        atual->proximo = NULL;
        atual->anterior = NULL;
    }
}

int main()
{
    char opc, lst;
    int valor;
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();
    while (scanf("\n%c", &opc) != EOF)
    {
        scanf(" %c", &lst);
        if (opc == 'I' || opc == 'E')
            scanf("%d", &valor);

        Lista* list;
        list = lst == 'A' ? l1 : l2;
        switch (opc)
        {
        case 'I':
            adicionar(list, valor);
            break;
        case 'M':
            listarInicioFim(list);
            break;
        case 'R':
            listarFimInicio(list);
            break;
        case 'E':
            remover(list, valor);
            break;
        }
    }
    return 0;
}