#include <stdio.h>

int MENOR_INT = -2147483648; // 2^31

int main()
{
    int N;

    scanf("%d", &N);

    int vetor[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int maior = MENOR_INT;
    int indice = -1;
    for (int i = 0; i < N; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
            indice = i;
        }
    }

    int maior2 = MENOR_INT;
    int indice2 = -1;
    for (int i = 0; i < N; i++)
    {
        if (i == indice)
            continue;
        if (vetor[i] > maior2)
        {
            maior2 = vetor[i];
            indice2 = i;
        }
    }

    printf("%d %d\n", indice2, maior2);

    return 0;
}