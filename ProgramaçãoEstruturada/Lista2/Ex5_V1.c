#include <stdio.h>

int main()
{
    int qntLinha, qntColuna;
    int matriz[1000][1000];
    int matrizTransposta[1000][1000];

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &qntLinha);

    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &qntColuna);

    for (int i = 0; i < qntLinha; i++)    
        for (int j = 0; j < qntColuna; j++)
        {
            printf("\nDigite o valor da linha %d coluna %d da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

    for (int i = 0; i < qntLinha; i++)    
        for (int j = 0; j < qntColuna; j++)
            matrizTransposta[j][i] = matriz[i][j];

    for (int i = 0; i < qntLinha; i++)
        for (int j = 0; j < qntColuna; j++)
            printf("\nMATRIZ TRANSPOSTA - posição {%d, %d} -> (%d)", i, j, matrizTransposta[i][j]);

    return 0;
}