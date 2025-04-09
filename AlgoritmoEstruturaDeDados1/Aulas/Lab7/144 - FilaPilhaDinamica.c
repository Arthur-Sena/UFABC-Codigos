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

struct PilhaDinamica
{
    struct Item *topo;
    struct Item *base;
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
    // printf("<%d>\n", remover->valor);
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
    // printf("[%d]\n", remover->valor);
    free(remover);
}

void mostrarPilha(struct PilhaDinamica *pilha)
{
    struct Item *atual = pilha->topo;
    
    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        // printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "\n");
        atual = atual->proximo;
    }
}

void empilharFila(struct PilhaDinamica *pilha, struct FilaDinamica *fila)
{
    struct PilhaDinamica *temp = criarPilha();

    struct Item *atual = fila->inicio;
    while (atual != NULL)
    {
        empilhar(temp, atual->valor);
        atual = atual->proximo;
    }

    while (!pilhaVazia(temp))
    {
        empilhar(pilha, temp->topo->valor);
        desempilhar(temp);
    }
    free(temp);
}

int main()
{
    struct FilaDinamica *fila = criarFila();
    struct PilhaDinamica *pilha = criarPilha();

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
        case 'P':
            pilha = criarPilha();
            empilharFila(pilha, fila);
            break;
        case 'M':
            mostrarPilha(pilha);
            break;
        }
    }

    return 0;
}
