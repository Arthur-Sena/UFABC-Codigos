#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct tHeap
{
    int *itens;
    int quantidade;
    int tamanho;
};

struct tHeap criarHeap(int n)
{
    struct tHeap h;
    h.itens = (int *)malloc(n * sizeof(int));
    h.quantidade = 0;
    h.tamanho = n;
    return h;
}

int filhoEsquerda(int p)
{
    return (2 * p) + 1;
}

int filhoDireita(int p)
{
    return (2 * p) + 2;
}

int ultimoPai(int n)
{
    return (n / 2) - 1;
}

void peneirar(struct tHeap *h, int p)
{
    int maior = p;
    int filhoE = filhoEsquerda(p);
    int filhoD = filhoDireita(p);

    if (filhoD < h->quantidade && h->itens[filhoD] > h->itens[maior])
        maior = filhoD;

    if (filhoE < h->quantidade && h->itens[filhoE] > h->itens[maior])
        maior = filhoE;

    if (maior != p)
    {
        troca(&h->itens[maior], &h->itens[p]);
        peneirar(h, maior);
    }
}

void construirHeap(struct tHeap *h)
{
    for (int i = ultimoPai(h->quantidade); i >= 0; i--)
        peneirar(h, i);
}

void inserirVetor(struct tHeap *h, int valor)
{
    if (h->quantidade < h->tamanho)
    {
        h->itens[h->quantidade++] = valor;
        construirHeap(h);
    }
}

void removerMax(struct tHeap *h)
{
    if (h->quantidade > 0)
    {
        troca(&h->itens[0], &h->itens[h->quantidade - 1]);
        h->quantidade--;
        printf("%d\n", h->itens[h->quantidade]);
        construirHeap(h);
    }

}

void mostrarVetor(struct tHeap h)
{
    for (int i = 0; i < h.quantidade; i++)
        printf("%d%s", h.itens[i], i < h.quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct tHeap heap = criarHeap(n);

    char opc;
    while (scanf("%c", &opc) != EOF)
    {

        switch (opc)
        {
        case 'I':
            int valor;
            scanf("%d", &valor);
            inserirVetor(&heap, valor);
            break;

        case 'M':
            mostrarVetor(heap);
            break;

        case 'R':
            removerMax(&heap);
            break;

        default:
            break;
        }
    }
    return 0;
}