#include <stdio.h>
#include <stdlib.h>

struct PilhaString
{
    int *itens;
    int quantidade;
    int tamanho;
};

struct PilhaString criarPilha(struct PilhaString *pilha, int tamanho)
{
    pilha->itens = (int *)malloc(tamanho * sizeof(int));
    pilha->quantidade = 0;
    pilha->tamanho = tamanho;
    return *pilha;
}

int pilhaCheia(struct PilhaString *pilha)
{
    return pilha->quantidade == pilha->tamanho;
}

int pilhaVazia(struct PilhaString *pilha)
{
    return pilha->quantidade == 0;
}

void empilha(struct PilhaString *pilha, int valor)
{
    if (!pilhaCheia(pilha))
        pilha->itens[pilha->quantidade++] = valor;
}

void desempilha(struct PilhaString *pilha)
{
    if (!pilhaVazia(pilha))
        pilha->quantidade--;
}

int topo(struct PilhaString *pilha)
{
    if (!pilhaVazia(pilha))
        return pilha->itens[pilha->quantidade - 1];
    return -1;
}

void imprimirTopoBase(struct PilhaString *pilha)
{
    for (int i = pilha->quantidade - 1; i >= 0; i--)
        printf("%d%s", pilha->itens[i], i != 0 ? " " : "\n");
}

void imprimirBaseTopo(struct PilhaString *pilha)
{
    for (int i = 0; i < pilha->quantidade; i++)
        printf("%d%s", pilha->itens[i], i != pilha->quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    struct PilhaString pilha;
    criarPilha(&pilha, n);

    char op;
    int valor;
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf(" %d", &valor);
            empilha(&pilha, valor);
            break;
        case 'D':
            desempilha(&pilha);
            break;
        case 'T':
            if (!pilhaVazia(&pilha))
                printf("%d\n", topo(&pilha));
            break;
        case 'X':
            imprimirTopoBase(&pilha);
            break;
        case 'B':
            imprimirBaseTopo(&pilha);
            break;
        }
    }

    return 0;
}