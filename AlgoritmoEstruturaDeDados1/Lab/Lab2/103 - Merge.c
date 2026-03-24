#include <stdio.h>
#include <stdlib.h>

int N;

void imprimeVetor(int *v)
{
    printf("%d", v[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", v[i]);
    printf("\n");
}

void intercala(int *v, int e, int m, int d)
{
    int *temp, i, fim_esq = m - 1, tam = d - e + 1;
    temp = (int *)malloc(tam * sizeof(int));
    for (i = 0; e <= fim_esq && m <= d; i++)
        if (v[e] < v[m])
        {
            temp[i] = v[e];
            e++;
        }
        else
        {
            temp[i] = v[m];
            m++;
        }
    for (; e <= fim_esq; e++, i++)
        temp[i] = v[e];
    for (; m <= d; m++, i++)
        temp[i] = v[m];
    for (i = tam - 1; i >= 0; i--, d--)
        v[d] = temp[i];
    free(temp);
}

void mergeSort(int *v, int e, int d)
{
    int meio;
    if (e < d)
    {
        meio = (d + e) / 2;
        
        mergeSort(v, e, meio);
        mergeSort(v, meio + 1, d);

        imprimeVetor(v);

        intercala(v, e, meio + 1, d);
    }
}

int main()
{
    scanf("%d", &N);

    int v[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    imprimeVetor(v);

    mergeSort(v, 0, N - 1);

    imprimeVetor(v);

    return 0;
}