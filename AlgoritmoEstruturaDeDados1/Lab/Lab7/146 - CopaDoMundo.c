#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Selecao
{
    char letra;
    int gols;
    struct Selecao *seguinte;
};

struct ListaDinamica
{
    struct Selecao *cabeca;
};

void inicializarLista(struct ListaDinamica *lista)
{
    lista->cabeca = NULL;
}

int listaVazia(struct ListaDinamica *lista)
{
    return lista->cabeca == NULL;
}

void inserirSelecao(struct ListaDinamica *lista, char letra)
{
    struct Selecao *novo = (struct Selecao *)malloc(sizeof(struct Selecao));
    novo->letra = letra;
    novo->gols = 0;
    novo->seguinte = NULL;

    struct Selecao *atual = lista->cabeca;
    struct Selecao *anterior = NULL;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->seguinte;
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

// void remover(struct ListaDinamica *lista, int valor)
// {
//     Node *atual = lista->cabeca;
//     Node *anterior = NULL;

//     while (atual != NULL && atual->valor != valor)
//     {
//         anterior = atual;
//         atual = atual->seguinte;
//     }

//     if (atual == NULL)
//         return;

//     if (anterior == NULL)
//         lista->cabeca = atual->seguinte;
//     else
//         anterior->seguinte = atual->seguinte;

//     free(atual);
// }

// void imprimir(struct ListaDinamica *lista)
// {
//     struct Selecao *atual = lista->cabeca;

//     while (atual != NULL)
//     {
//         printf("%c%d%s", atual->letra, atual->gols, atual->seguinte != NULL ? " " : "\n");
//         atual = atual->seguinte;
//     }
// }

void inserirResultados(struct ListaDinamica *lista)
{
    struct Selecao *atual = lista->cabeca;
    char letra;
    int i = 1;

    while (atual != NULL)
    {
        scanf("\n %d %d", &atual->gols, &atual->seguinte->gols);

        // atual = vencedor
        if (atual->gols < atual->seguinte->gols)
            atual->letra = atual->seguinte->letra;

        // o seguinte é eliminado
        struct Selecao *perdedor = atual->seguinte;
        atual->seguinte = atual->seguinte->seguinte;
        free(perdedor);

        atual->gols = 0;

        atual = atual->seguinte;
    }
}

int main()
{
    struct ListaDinamica selecoes;
    inicializarLista(&selecoes);

    for (char letra = 'A'; letra <= 'P'; letra++)
    {
        inserirSelecao(&selecoes, letra);
    }

    while (selecoes.cabeca->seguinte != NULL)
    {
        inserirResultados(&selecoes);
    }

    printf("%c\n", selecoes.cabeca->letra);

    return 0;
}