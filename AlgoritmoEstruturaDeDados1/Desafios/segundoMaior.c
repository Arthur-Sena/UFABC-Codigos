#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int qntElementos;

    scanf("%d", &qntElementos);
    if (qntElementos == 0)
        return 0;

    int* vetor = (int*) malloc(qntElementos * sizeof(int));
    
    for (int i = 0; i < qntElementos; i++)
        scanf("%d", &vetor[i]);

    int maiorNum = INT_MIN, indiceMaiorNum = 0, segundoMaiorNum = INT_MIN + 1, indiceSegundoMaiorNum = 0;

    for (int j = 0; j < qntElementos; j++)
        if (vetor[j] > maiorNum)
        {
            indiceSegundoMaiorNum = indiceMaiorNum;
            segundoMaiorNum = maiorNum;
            maiorNum = vetor[j];
            indiceMaiorNum = j;
        }    
        else if (vetor[j] > segundoMaiorNum)
        {
            segundoMaiorNum = vetor[j];
            indiceSegundoMaiorNum = j;
        }
      
    printf("%d %d\n", indiceSegundoMaiorNum, segundoMaiorNum);
    return 0;
}