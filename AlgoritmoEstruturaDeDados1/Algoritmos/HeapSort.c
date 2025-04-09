#include<stdio.h>
#include<stdlib.h>

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

void peneirar(int *h, int n, int p)
{
    int maior = p, aux;
    if(filhoEsquerda(p) < n && h[filhoEsquerda(p)] > h[maior])
    {
        maior = filhoEsquerda(p);
    }
    if(filhoDireita(p) < n && h[filhoDireita(p)] > h[maior])
    {
        maior = filhoDireita(p);
    }
    if(maior != p)
    {
        aux = h[p];
        h[p] = h[maior];
        h[maior] = aux;
        peneirar(h, n, maior);
    }
}

void construirHeap(int *h, int n)
{
    int i;
    for(i=ultimoPai(n); i>=0; i--)
    {
        peneirar(h, n, i);
    }
}

void removerMax(int *h, int n)
{
    int aux = h[0];
    h[0] = h[n-1];
    h[n-1] = aux;
}

void heapSort(int *h, int n)
{
    int i;
    construirHeap(h, n);
    for(i=n; i>0; i--)
    {
        removerMax(h, i);
        peneirar(h, i-1, 0);
    }
}

void mostrarVetor(int *v, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d%s", v[i], i<n-1?" ":"\n");
    }
}

int main()
{
    int *v, n, i;

    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }

    heapSort(v, n);
    mostrarVetor(v, n);
    return 0;
}