#include <stdio.h>

void preencherMatriz(int matriz[1000][1000], int linhas, int colunas){
    for (int i = 0; i < linhas; i++) 
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor da posição [%d][%d] da matriz: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
}

void calcularTransposta(int matriz[1000][1000], int transposta[1000][1000], int linhas, int colunas){
    for (int i = 0; i < linhas; i++) 
        for (int j = 0; j < colunas; j++) 
            transposta[j][i] = matriz[i][j];     
}

void exibirMatriz(int matriz[1000][1000], int linhas, int colunas){
    for (int i = 0; i < linhas; i++) 
    {
        for (int j = 0; j < colunas; j++) 
            printf("%d ", matriz[i][j]);        
        printf("\n");
    }
}

int main() {
    int qntLinha, qntColuna;
    int matriz[1000][1000];
    int matrizTransposta[1000][1000];

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &qntLinha);

    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &qntColuna);

    printf("\nPreenchendo a matriz:\n");
    preencherMatriz(matriz, qntLinha, qntColuna);

    calcularTransposta(matriz, matrizTransposta, qntLinha, qntColuna);

    printf("\nMatriz Transposta:\n");
    exibirMatriz(matrizTransposta, qntColuna, qntLinha);

    return 0;
}