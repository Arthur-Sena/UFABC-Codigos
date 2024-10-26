#include <stdio.h>

int verificarArredores(int espaco[1000][1000], int linha, int coluna) {
    int isSabreDeLuz = 1;
    //printf("Linha is  [%d][%d] \n", linha, coluna);
    for (int x = linha - 1; x <= linha + 1; x++)
        for (int y = coluna - 1; y <= coluna + 1; y++)
            if (espaco[x][y] != 7 && (x != linha && y != coluna))
            {
                isSabreDeLuz = 0;
                //printf("Falha in  [%d][%d]", x, y);
                return isSabreDeLuz;
            }
    printf("Sabre de luz encontrado no espaco [%d][%d] \n", linha, coluna);
    return isSabreDeLuz;
}

int main() {
    int espaco[1000][1000];
    int qntLinhas, qntColunas;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &qntLinhas);

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &qntColunas);

    for (int i = 0; i < qntLinhas; i++)
        for (int j = 0; j < qntColunas; j++)
        {
            printf("Digite o valor [%d][%d]: ", i, j);
            scanf("%d", &espaco[i][j]);
        }
    
    //Buscando coordenadas do sabre de luz
    for (int i = 0; i < qntLinhas; i++)
        for (int j = 0; j < qntColunas; j++)
            if (espaco[i][j] == 42)
                verificarArredores(espaco, i, j);
        
    return 0;
}