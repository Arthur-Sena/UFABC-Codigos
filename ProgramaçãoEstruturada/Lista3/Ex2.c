#include <stdio.h>

int sumDiagonalPrincipal(int matriz[1000][1000], int n) {
    int sm = 0;
    for (int i = 0; i < n; i++)
        sm += matriz[i][i];
    return sm;
}

int medDiagonalSuperior(int matriz[1000][1000], int n) {
    int sm = 0, qtd = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (j > i) {
                sm += matriz[i][j];
                qtd++;
            }
                
    if (qtd > 0)
        return sm / qtd;
    else
        return 0;  
}

int main() {
    int matriz[1000][1000];
    int n;
    char c;

    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);

    printf("Inicialização da MATRIZ:\n");
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            printf("MATRIZ - Digite o valor da posição {%d, %d}: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }

    printf("\nDigite a ação:\n'S' para Soma dos elementos da diagonal Principal;\n'M' para Média dos elementos acima da diagonal principal\nOpção: ");
    scanf(" %c", &c);

    if (c == 'S') 
        printf("\nSoma da Diagonal Principal: %d\n", sumDiagonalPrincipal(matriz, n));
    else if (c == 'M')
        printf("\nMédia dos Elementos que estão acima da Diagonal Principal: %d\n", medDiagonalSuperior(matriz, n));
    else 
        printf("\nAção Incorreta!\n");
    
    return 0;
}
