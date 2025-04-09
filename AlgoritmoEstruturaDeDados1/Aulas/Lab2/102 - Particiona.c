#include <stdio.h>

void trocar(int *a, int *b)
{
    int troca = *a;
    *a = *b;
    *b = troca;
}

int main()
{
    int q, p;
    scanf("%d", &q);
    scanf("%d", &p);

    int V[q];

    for (int i = 0; i < q; i++)
        scanf("%d", &V[i]);

    int i = 0, pm = -1;

    trocar(&V[p], &V[q - 1]);


    p = q - 1;

    while (i < q-1)
    {
        if (V[i] < V[p])
        {
            pm++;
            trocar(&V[i], &V[pm]);
        }
        i++;
    }
    pm++;
    trocar(&V[p], &V[pm]);

    for (int i = 0; i < q; i++)
        printf("%d\n", V[i]);

    return 0;
}