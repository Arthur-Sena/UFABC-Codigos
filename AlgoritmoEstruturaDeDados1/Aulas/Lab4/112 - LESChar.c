#include <stdio.h>
#include <stdlib.h>

struct LESstring
{
    char *itens;
    int quantidade;
    int tamanho;
};

struct LESstring criarLista(struct LESstring *les, int tamanho)
{
    les->itens = (char *)malloc(tamanho * sizeof(char));
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

int buscar(struct LESstring *les, char letra)
{
    for (int i = 0; i < les->quantidade; i++)
        if (les->itens[i] == letra)
            return i;
    return -1;
}

void inserir(struct LESstring *les, char letra)
{
    if (!listaCheia(les))
    {
        int i = buscar(les, letra);
        if (i == -1)
        {
            int j = les->quantidade;
            while (j > 0 && les->itens[j - 1] > letra)
            {
                les->itens[j] = les->itens[j - 1];
                j--;
            }
            les->itens[j] = letra;
            les->quantidade++;
        }
    }
}

void remover(struct LESstring *les, char letra)
{
    if (!listaVazia(les))
    {
        int i = buscar(les, letra);

        if (i < les->quantidade && i != -1)
        {
            les->quantidade--;
            for (int j = i; j < les->quantidade; j++)
                les->itens[j] = les->itens[j + 1];
        }
    }
}

void imprimir(struct LESstring *les)
{
    for (int i = 0; i < les->quantidade; i++)
        printf("%c%s", les->itens[i], i < les->quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct LESstring les;
    criarLista(&les, n);

    char op;
    char letra;
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf(" %c", &letra);
            inserir(&les, letra);
            break;

        case 'R':
            scanf(" %c", &letra);
            remover(&les, letra);
            break;

        case 'B':
            scanf(" %c", &letra);
            printf("%s\n", buscar(&les, letra) != -1 ? "SIM" : "NAO");
            break;

        case 'M':
            imprimir(&les);
            break;

        default:
            break;
        }
    }
}