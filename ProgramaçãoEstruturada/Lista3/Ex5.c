#include <stdio.h>

int main() {
    int tamMatriz;

    printf("Digite o tamanho da matriz (entre 1 e 100) : ");
    scanf("%d", &tamMatriz);

    if (tamMatriz > 100){
        printf("Erro: Matriz maior que o esperado ");
        return 0;
    }

    int matriz[tamMatriz][tamMatriz];

    for (int i = 0; i < tamMatriz; i++)
        for (int j = 0; j < tamMatriz; j++)
        {
            int menorValor = i < j ? i : j;

            if (tamMatriz - i - 1 < menorValor) 
                menorValor = tamMatriz - i - 1;
            if (tamMatriz - j - 1 < menorValor) 
                menorValor = tamMatriz - j - 1;
            matriz[i][j] = menorValor + 1;
        }

    for (int i = 0; i < tamMatriz; i++){
        for (int j = 0; j < tamMatriz; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

    return 0;
}