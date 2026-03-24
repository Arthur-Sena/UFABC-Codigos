#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LESstring
{
    char (*itens)[100];
    int quantidade;
    int tamanho;
};

struct LESstring criarLista(struct LESstring *les, int tamanho)
{
    les->itens = (char (*)[100])malloc(tamanho * sizeof(char[100]));
    les->quantidade = 0;
    les->tamanho = tamanho;
    return *les;
}

int listaCheia(struct LESstring *les)
{
    return les->quantidade == les->tamanho;
}

int listaVazia(struct LESstring *les)
{
    return les->quantidade == 0;
}

int buscar(struct LESstring *les, char *palavra)
{
    for (int i = 0; i < les->quantidade; i++)
        if (strcmp(les->itens[i], palavra) == 0)
            return i;
    return -1;
}

void inserir(struct LESstring *les, char *palavra)
{
    if (!listaCheia(les))
    {
        int i = buscar(les, palavra);
        if (i == -1)
        {
            int j = les->quantidade;
            while (j > 0 && strcmp(les->itens[j - 1], palavra) > 0)
            {
                strcpy(les->itens[j], les->itens[j - 1]);
                j--;
            }
            strcpy(les->itens[j], palavra);
            les->quantidade++;
        }
    }
}

void remover(struct LESstring *les, char *palavra)
{
    if (!listaVazia(les))
    {
        int i = buscar(les, palavra);

        if (i < les->quantidade && i != -1)
        {
            les->quantidade--;
            for (int j = i; j < les->quantidade; j++)
                strcpy(les->itens[j], les->itens[j + 1]);
        }
    }
}

void imprimir(struct LESstring *les)
{
    for (int i = 0; i < les->quantidade; i++)
        printf("%s%s", les->itens[i], i < les->quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct LESstring les;
    criarLista(&les, n);

    char op;
    char palavra[100];
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf(" %s", palavra);
            inserir(&les, palavra);
            break;

        case 'R':
            scanf(" %s", palavra);
            remover(&les, palavra);
            break;

        case 'B':
            scanf(" %s", palavra);
            printf("%s\n", buscar(&les, palavra) != -1 ? "SIM" : "NAO");
            break;

        case 'M':
            imprimir(&les);
            break;

        default:
            break;
        }
    }
}