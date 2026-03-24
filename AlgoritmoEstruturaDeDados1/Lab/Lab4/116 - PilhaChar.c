#include <stdio.h>
#include <stdlib.h>

struct PilhaString
{
    char *itens;
    int quantidade;
    int tamanho;
};

struct PilhaString criarPilha(struct PilhaString *pilha, int tamanho)
{
    pilha->itens = (char *)malloc(tamanho * sizeof(char));
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

void empilha(struct PilhaString *pilha, char letra)
{
    if (!pilhaCheia(pilha))
        pilha->itens[pilha->quantidade++] = letra;
}

void desempilha(struct PilhaString *pilha)
{
    if (!pilhaVazia(pilha))
        pilha->quantidade--;
}

char topo(struct PilhaString *pilha)
{
    if (!pilhaVazia(pilha))
        return pilha->itens[pilha->quantidade -1];
    return '\0';
}

void imprimirTopoBase(struct PilhaString *pilha)
{
    for (int i = pilha->quantidade - 1; i >= 0; i--)
        printf("%c%s", pilha->itens[i], i != 0 ? " " : "\n");
}

void imprimirBaseTopo(struct PilhaString *pilha)
{
    for (int i = 0; i < pilha->quantidade; i++)
        printf("%c%s", pilha->itens[i], i != pilha->quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    struct PilhaString pilha;
    criarPilha(&pilha, n);

    char op;
    char letra;
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'E':
            if (scanf(" %c", &letra) == 1)
                empilha(&pilha, letra);
            break;
        case 'D':
            desempilha(&pilha);
            break;
        case 'T':
            if (!pilhaVazia(&pilha))
            printf("%c\n", topo(&pilha));
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