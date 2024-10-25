#include <stdio.h>

void preencherMatriz(int matriz[1000][1000], int linhas, int colunas, char nome) {
    for (int i = 0; i < linhas; i++) 
        for (int j = 0; j < colunas; j++) {
            printf("MATRIZ %c - Digite o valor da posição {%d, %d}: ", nome, i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }   
}

int main() {
    int vA[1000][1000], vB[1000][1000];
    int n, m;

    printf("Digite a quantidade de Linhas: ");
    scanf("%d", &n);

    printf("Digite a quantidade de Colunas: ");
    scanf("%d", &m);

    printf("\nPreenchendo Matriz A:\n");
    preencherMatriz(vA, n, m, 'A');

    printf("\nPreenchendo Matriz B:\n");
    preencherMatriz(vB, n, m, 'B');

    printf("\nResultado da Matriz C (A + B):\n");
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            int soma = vA[i][j] + vB[i][j];
            printf("MATRIZ C - posição {%d, %d} -> (%d + %d) : %d\n", i + 1, j + 1, vA[i][j], vB[i][j], soma);
        }
    
    return 0;
}