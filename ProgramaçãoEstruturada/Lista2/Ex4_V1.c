#include <stdio.h>

int main()
{
    int vA[1000][1000], vB[1000][1000];
    int n, m;

    printf("Digite a quantidade de Linhas: ");
    scanf("%d", &n);

    printf("Digite o quantidade de Colunas: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++)    
        for (int j = 0; j < m; j++)
        {
            printf("\nMATRIZ A - Digite o valor da posição {%d, %d}: ", i + 1, j + 1);
            scanf("%d", &vA[i][j]);
        }    

    for (int i = 0; i < n; i++)    
        for (int j = 0; j < m; j++)
        {
            printf("\nMATRIZ B - Digite o valor da posição {%d, %d}: ", i + 1, j + 1);
            scanf("%d", &vB[i][j]);
        }    

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            printf("\nMATRIZ C - posição {%d, %d} -> (%d + %d) : {%d} ", i + 1, j + 1, vA[i][j], vB[i][j], vA[i][j] + vB[i][j]);

    return 0;
}