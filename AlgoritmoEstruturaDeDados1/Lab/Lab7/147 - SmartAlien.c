#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int valor;
    struct Item *proximo;
};

struct FilaDinamica
{
    struct Item *inicio;
    struct Item *fim;
};

struct PilhaDinamica
{
    struct Item *topo;
};

int filaVazia(struct FilaDinamica *fila)
{
    return fila->inicio == NULL;
}

struct FilaDinamica *criarFila()
{
    struct FilaDinamica *fila = (struct FilaDinamica *)malloc(sizeof(struct FilaDinamica));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
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
}

void desenfileirar(struct FilaDinamica *fila)
{
    if (filaVazia(fila))
        return;

    struct Item *remover = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    // free(remover);
}
void mostrarFila(struct FilaDinamica *fila)
{
    struct Item *atual = fila->inicio;
    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        // printf("%d%s", atual->valor, atual->proximo != NULL ? " " : "\n");
        atual = atual->proximo;
    }
}

struct PilhaDinamica *criarPilha()
{
    struct PilhaDinamica *pilha = (struct PilhaDinamica *)malloc(sizeof(struct PilhaDinamica));
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

    if (!pilhaVazia(pilha))
        novo->proximo = pilha->topo;

    pilha->topo = novo;
}

void desempilhar(struct PilhaDinamica *pilha)
{
    if (!pilhaVazia(pilha))
        pilha->topo = pilha->topo->proximo;
}

void mostrarPilha(struct PilhaDinamica *pilha)
{
    struct Item *atual = pilha->topo;
    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

// void empilharFila(struct PilhaDinamica *pilha, struct FilaDinamica *fila)
// {
//     while (!filaVazia(fila))
//     {
//         empilhar(pilha, fila->inicio->valor);
//         desenfileirar(fila);
//     }
// }

void enfileirarPilha(struct PilhaDinamica *pilha, struct FilaDinamica *fila)
{
    while (!pilhaVazia(pilha))
    {
        enfileirar(fila, pilha->topo->valor);
        desempilhar(pilha);
    }
}

int proximoPrimo(int n)
{
    int i, j;
    for (i = n + 1;; i++)
    {
        for (j = 2; j * j <= i; j++)
            if (i % j == 0)
                break;
        if (j * j > i)
            return i;
    }
}

int main()
{
    struct PilhaDinamica *pilhaA = criarPilha();
    struct PilhaDinamica *pilhaB = criarPilha();
    struct FilaDinamica *filaA = criarFila();
    struct FilaDinamica *filaB = criarFila();

    int N, R, valor, primoAtual = 2;

    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &valor);
        empilhar(pilhaA, valor);
    }

    for (int i = 0; i < R; i++)
    {
        enfileirarPilha(pilhaA, filaA);

        while (!filaVazia(filaA))
        {
            if (filaA->inicio->valor % primoAtual == 0)
                empilhar(pilhaB, filaA->inicio->valor);
            else
                empilhar(pilhaA, filaA->inicio->valor);
            desenfileirar(filaA);
        }

        while (!pilhaVazia(pilhaB))
        {
            enfileirar(filaB, pilhaB->topo->valor);
            desempilhar(pilhaB);
        }

        primoAtual = proximoPrimo(primoAtual);
    }

    mostrarFila(filaB);
    mostrarPilha(pilhaA);

    return 0;
}