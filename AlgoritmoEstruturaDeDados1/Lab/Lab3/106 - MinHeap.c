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
};

struct tHeap criarHeap(int n)
{
    struct tHeap h;
    h.itens = (int *)malloc(n * sizeof(int));
    h.quantidade = n;
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
    int menor = p;
    int filhoE = filhoEsquerda(p);
    int filhoD = filhoDireita(p);

    if (filhoD < h->quantidade && h->itens[filhoD] < h->itens[menor])
        menor = filhoD;

    if (filhoE < h->quantidade && h->itens[filhoE] < h->itens[menor])
        menor = filhoE;

    if (menor != p)
    {
        troca(&h->itens[menor], &h->itens[p]);
        peneirar(h, menor);
    }
}

void construirHeap(struct tHeap *h)
{
    for (int i = ultimoPai(h->quantidade); i >= 0; i--)
        peneirar(h, i);
}

void mostrarVetor(struct tHeap h)
{
    for (int i = 0; i < h.quantidade; i++)
        printf("%d%s", h.itens[i], i < h.quantidade - 1 ? " " : "\n");
}

int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
    {
        struct tHeap heap = criarHeap(n);

        for (int i = 0; i < n; i++)
            scanf("%d", &heap.itens[i]);

        construirHeap(&heap);
        mostrarVetor(heap);
    }
    return 0;
}