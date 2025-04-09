#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qntElementos;
    while (1)
    {
        scanf("%d", &qntElementos);
        if (qntElementos == 0)
            break;

        int* vetor = (int*)malloc(qntElementos * sizeof(int));
        for (int i = 0; i < qntElementos; i++)
            scanf("%d", &vetor[i]);

        int indiceMaiorVetor = 0, maiorValor = vetor[0];
        for (int j = 1; j < qntElementos; j++ )
        {
            if (vetor[j] > maiorValor)
            {
                indiceMaiorVetor = j;
                maiorValor = vetor[j];
            }
        }

        printf("%d %d\n", indiceMaiorVetor, maiorValor);
        free(vetor);
    }
    return 0;
}