#include <stdio.h>
#include <stdlib.h>

struct LESstring
{
    float *itens;
    int quantidade;
    int tamanho;
};

struct LESstring criarLista(struct LESstring *les, int tamanho)
{
    les->itens = (float *)malloc(tamanho * sizeof(float));
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

int buscar(struct LESstring *les, float valor)
{
    for (int i = 0; i < les->quantidade; i++)
        if (les->itens[i] == valor)
            return i;
    return -1;
}

void inserir(struct LESstring *les, float valor)
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

void remover(struct LESstring *les, float valor)
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

void imprimir(struct LESstring *les)
{
    for (int i = 0; i < les->quantidade; i++)
    {
        if (les->itens[i] == (int)les->itens[i])
            printf("%d%s", (int)les->itens[i], i < les->quantidade - 1 ? " " : "\n");
        else
            printf("%.1f%s", les->itens[i], i < les->quantidade - 1 ? " " : "\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct LESstring les;
    criarLista(&les, n);

    char op;
    float valor;
    while (scanf("\n%c", &op) != EOF)
    {
        switch (op)
        {
        case 'I':
            scanf("%f", &valor);
            inserir(&les, valor);
            break;

        case 'R':
            scanf("%f", &valor);
            remover(&les, valor);
            break;

        case 'B':
            scanf("%f", &valor);
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