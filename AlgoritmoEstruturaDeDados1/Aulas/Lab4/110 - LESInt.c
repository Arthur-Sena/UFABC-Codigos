#include <stdio.h>
#include <stdlib.h>

struct LESint
{
    int *itens;
    int quantidade;
    int tamanho;
};

struct LESint criarLista(struct LESint *les, int tamanho)
{
    les->itens = (int *)malloc(tamanho * sizeof(int));
    les->quantidade = 0;
    les->tamanho = tamanho;
    return *les;
}

int listaCheia(struct LESint *les)
{
    return les->quantidade == les->tamanho;
}

int listaVazia(struct LESint *les)
{
    return les->quantidade == 0;
}

int buscar(struct LESint *les, int valor)
{
    for (int i = 0; i < les->quantidade; i++)
        if (les->itens[i] == valor)
            return i;
    return -1;
}

void inserir(struct LESint *les, int valor)
{
    if (!listaCheia(les))
    {
        int i = buscar(les, valor);
        if (i == -1)
        {
            int j = les->quantidade;
            while (j > 0 && les->itens[j - 1] > valor)
            {
                les->itens[j] = les->itens[j - 1];
                j--;
            }
            les->itens[j] = valor;
            les->quantidade++;
        }
    }
}

void remover(struct LESint *les, int valor)
{
    if (!listaVazia(les))
    {
        int i = buscar(les, valor);

        if (i < les->quantidade && i != -1)
        {
            les->quantidade--;
            for (int j = i; j < les->quantidade; j++)
                les->itens[j] = les->itens[j + 1];
        }
    }
}

void imprimir(struct LESint *les)
{
    for (int i = 0; i < les->quantidade; i++)
        printf("%d%s", les->itens[i], i < les->quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct LESint les;
    criarLista(&les, n);

    char op;
    int valor;
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf("%d", &valor);
            inserir(&les, valor);
            break;

        case 'R':
            scanf("%d", &valor);
            remover(&les, valor);
            break;

        case 'B':
            scanf("%d", &valor);
            printf("%s\n", buscar(&les, valor) != -1 ? "SIM" : "NAO");
            break;

        case 'M':
            imprimir(&les);
            break;

        default:
            break;
        }
    }
}