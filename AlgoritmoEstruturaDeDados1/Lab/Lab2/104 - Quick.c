#include <stdio.h>

int N;

void imprimeVetor(int *v)
{
    printf("%d", v[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", v[i]);
    printf("\n");
}

void troca(int *a, int *b)
{
    int troca = *a;
    *a = *b;
    *b = troca;
}

int particiona(int *v, int e, int d)
{
    int pm = e - 1, i, aux;
    for (i = e; i < d; i++)
    {
        if (v[i] <= v[d])
        {
            pm++;
            troca(&v[pm], &v[i]);
        }
        imprimeVetor(v);
    }
    troca(&v[d], &v[pm + 1]);
    imprimeVetor(v);

    return pm + 1;
}

void quickSort(int *v, int e, int d)
{
    int p;
    if (e < d)
    {
        p = particiona(v, e, d);
        quickSort(v, e, p - 1);
        quickSort(v, p + 1, d);
    }
}

int main()
{
    scanf("%d", &N);

    int v[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    imprimeVetor(v);

    quickSort(v, 0, N - 1);

    imprimeVetor(v);

    return 0;
}