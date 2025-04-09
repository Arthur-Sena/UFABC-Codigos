#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int valor;
    struct Item *anterior;
    struct Item *proximo;
};

struct LDDE
{
    struct Item *inicio;
    struct Item *fim;
};

struct LDDE *criarLDDE()
{
    struct LDDE *lista = (struct LDDE *)malloc(sizeof(struct LDDE));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

int listaVazia(struct LDDE *lista)
{
    return lista->inicio == NULL;
}

void inserir(struct LDDE *lista, int valor)
{
    struct Item *novo = (struct Item *)malloc(sizeof(struct Item));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if (listaVazia(lista))
    {
        lista->inicio = lista->fim = novo;
        return;
    }

    struct Item *atual = lista->inicio;

    while (atual != NULL && atual->valor < valor)
        atual = atual->proximo;

    if (atual != NULL && atual->valor == valor) // Valor já existe
    {
        free(novo);
        return;
    }

    if (atual == NULL) // Inserir no final
    {
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    else if (atual == lista->inicio) // Inserir no início
    {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
    }
    else // Inserir no meio
    {
        novo->proximo = atual;
        novo->anterior = atual->anterior;
        atual->anterior->proximo = novo;
        atual->anterior = novo;
    }
}

void remover(struct LDDE *lista, int valor)
{
    if (listaVazia(lista))
        return;

    struct Item *atual = lista->inicio;

    while (atual != NULL && atual->valor < valor)
        atual = atual->proximo;

    if (atual == NULL || atual->valor != valor)
        return;

    if (atual->anterior != NULL)
        atual->anterior->proximo = atual->proximo;
    else
        lista->inicio = atual->proximo;

    if (atual->proximo != NULL)
        atual->proximo->anterior = atual->anterior;
    else
        lista->fim = atual->anterior;

    free(atual);
}

void mostrarLista(struct LDDE *lista)
{
    struct Item *atual = lista->inicio;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void mostrarListaReversa(struct LDDE *lista)
{
    struct Item *atual = lista->fim;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

int main()
{

    struct LDDE *listaA = criarLDDE();
    struct LDDE *listaB = criarLDDE();
    struct LDDE *lista;
    char opc, lst;
    int valor;

    while (scanf("\n%c", &opc) != EOF)
    {
        scanf(" %c", &lst);
        lista = lst == 'A' ? listaA : listaB;

        if (opc == 'I' || opc == 'E')
            scanf(" %d", &valor);

        switch (opc)
        {
        case 'I':
            inserir(lista, valor);
            break;

        case 'E':
            remover(lista, valor);
            break;

        case 'M':
            mostrarLista(lista);
            break;

        case 'R':
            mostrarListaReversa(lista);
            break;
        }
    }

    return 0;
}