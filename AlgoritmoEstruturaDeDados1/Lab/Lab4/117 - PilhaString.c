#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PilhaString
{
    char (*itens)[100];
    int quantidade;
    int tamanho;
};

struct PilhaString criarPilha(struct PilhaString *pilha, int tamanho)
{
    pilha->itens = (char(*)[100])malloc(tamanho * sizeof(char[100]));
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

void empilha(struct PilhaString *pilha, char *palavra)
{
    if (!pilhaCheia(pilha))
        strcpy(pilha->itens[pilha->quantidade++], palavra);
}

void desempilha(struct PilhaString *pilha)
{
    if (!pilhaVazia(pilha))
        pilha->quantidade--;
}

char *topo(struct PilhaString *pilha)
{
    if (!pilhaVazia(pilha))
        return pilha->itens[pilha->quantidade - 1];
    return "";
}

void imprimirTopoBase(struct PilhaString *pilha)
{
    for (int i = pilha->quantidade - 1; i >= 0; i--)
        printf("%s%s", pilha->itens[i], i != 0 ? " " : "\n");
}

void imprimirBaseTopo(struct PilhaString *pilha)
{
    for (int i = 0; i < pilha->quantidade; i++)
        printf("%s%s", pilha->itens[i], i != pilha->quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    struct PilhaString pilha;
    criarPilha(&pilha, n);

    char op;
    char palavra[100];
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            scanf(" %s", palavra);
            empilha(&pilha, palavra);
            break;
        case 'D':
            desempilha(&pilha);
            break;
        case 'T':
            if (!pilhaVazia(&pilha))
                printf("%s\n", topo(&pilha));
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