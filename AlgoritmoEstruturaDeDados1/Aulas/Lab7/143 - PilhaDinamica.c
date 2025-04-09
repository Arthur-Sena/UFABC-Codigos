#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    int valor;
    struct Item *proximo;
};

struct PilhaDinamica
{
    struct Item *topo;
    struct Item *base;
    int tamanho;
};

struct PilhaDinamica *criarPilha()
{
    struct PilhaDinamica *pilha = (struct PilhaDinamica *)malloc(sizeof(struct PilhaDinamica));
    pilha->topo = NULL;
    pilha->base = NULL;
    pilha->tamanho = 0;
    return pilha;
}

int pilhaVazia(struct PilhaDinamica *pilha)
{
    return pilha->topo == NULL;
}

void empilhar(struct PilhaDinamica *pilha, int valor)
{
    struct Item *novo = (struct Item *)malloc(sizeof(struct Item));
    novo->valor = valor;
    novo->proximo = NULL;

    if (pilhaVazia(pilha))
        pilha->base = novo;
    else
        novo->proximo = pilha->topo;

    pilha->topo = novo;
    pilha->tamanho++;
}

void desempilhar(struct PilhaDinamica *pilha)
{
    if (pilhaVazia(pilha))
        return;

    struct Item *remover = pilha->topo;

    pilha->topo = pilha->topo->proximo;

    if (pilha->topo == NULL)
        pilha->base = NULL;

    pilha->tamanho--;
    printf("[%d]\n", remover->valor);
    free(remover);
}

void mostrarPilha(struct PilhaDinamica *pilha)
{
    struct Item *atual = pilha->topo;

    while (atual != NULL)
    {
        printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "\n");
        atual = atual->proximo;
    }
}

int main()
{
    struct PilhaDinamica *pilha = criarPilha();

    char opc;
    int valor;

    while (scanf("\n%c", &opc) != EOF)
    {
        switch (opc)
        {
        case 'E':
            scanf(" %d", &valor);
            empilhar(pilha, valor);
            break;
        case 'D':
            desempilhar(pilha);
            break;
        case 'M':
            mostrarPilha(pilha);
            break;
        }
    }

    return 0;
}
