#include <stdio.h>

void trocaTempos(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int quantidade, trocas = 0;

    scanf("%d", &quantidade);
    float tempos[quantidade];

    for (int i = 0; i < quantidade; i++)
        scanf("%*d %*s %*s %f", &tempos[i]);

    for (int i = 0; i < quantidade; i++)
        for (int j = i + 1; j < quantidade; j++)
            if (tempos[i] > tempos[j])
            {
                trocaTempos(&tempos[i], &tempos[j]);
                trocas++;
            }

    printf("%d\n", trocas);

    return 0;
}