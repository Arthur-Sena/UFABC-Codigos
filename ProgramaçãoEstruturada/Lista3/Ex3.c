#include <stdio.h>

int validSolutionSudoku(int matriz[9][9])
{
    int retErro = 0;

    // Linhas
    for (int i = 0; i < 9; i++)
    {
        int stopAll = 0;
        int vCheck[9];
        for (int l = 0; l < 9; l++)
            vCheck[l] = 0;

        for (int j = 0; j < 9; j++)
            vCheck[matriz[i][j] - 1] += 1;

        for (int k = 0; k < 9; k++)
            if (vCheck[k] != 1)
            {
                retErro = 1;
                stopAll = 1;
                break;
            }

        if (stopAll)
            break;
    }

    if (retErro)
        return retErro;

    // Colunas
    for (int i = 0; i < 9; i++)
    {
        int stopAll = 0;
        int vCheck[9];
        for (int l = 0; l < 9; l++)
            vCheck[l] = 0;

        for (int j = 0; j < 9; j++)
            vCheck[matriz[j][i] - 1] += 1;

        for (int k = 0; k < 9; k++)
            if (vCheck[k] != 1)
            {
                retErro = 2;
                stopAll = 1;
                break;
            }
        if (stopAll)
            break;
    }

    if (retErro)
        return retErro;

    // Quadrantes
    int incrementLineQuadrantes = 0;
    int incrementColumnQuadrantes = 0;
    for (int qdcv = 0; qdcv < 3; qdcv++)
    {
        int stopAll = 0;
        for (int qdch = 0; qdch < 3; qdch++)
        {
            int vCheck[9];
            for (int l = 0; l < 9; l++)
                vCheck[l] = 0;

            for (int q = 0; q < 3; q++)
                for (int r = 0; r < 3; r++)
                    vCheck[matriz[q + incrementLineQuadrantes][r + incrementColumnQuadrantes] - 1] += 1;

            for (int k = 0; k < 9; k++)
                if (vCheck[k] != 1)
                {
                    retErro = 3;
                    stopAll = 1;
                    break;
                }
            if (stopAll)
                break;
            incrementColumnQuadrantes += 3;
        }
        incrementColumnQuadrantes = 0;
        incrementLineQuadrantes += 3;
        if (stopAll)
            break;
    }
    incrementLineQuadrantes = 0;

    return retErro;
}

void printSudoku(int matriz[9][9])
{
    printf("\nSUDOKU:");
    for (int i = 0; i < 9; i++)
    {
        if (i != 0 && i % 3 == 0)
            printf("\n----------------------\n");
        else
            printf("\n");
        for (int j = 0; j < 9; j++)
        {
            if (j != 0 && j % 3 == 0)            
                printf("| ");
            printf("%d ", matriz[i][j]);
        }
    }
}

int main()
{
    int matriz[9][9];
    int res;

    printf("Inicialização da MATRIZ (SUDOKU):\n");
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            printf("\n MATRIZ SUDOKU - Digite o valor da posição {%d, %d}:", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }

    printSudoku(matriz);
    printf("\n");
    res = validSolutionSudoku(matriz);

    if (res == 0)
        printf("\nSUDOKU VALIDO!");
    else if (res == 1)
        printf("\nSUDOKU INVALIDO! - Linhas");
    else if (res == 2)
        printf("\nSUDOKU INVALIDO! - Colunas");
    else if (res == 3)
        printf("\nSUDOKU INVALIDO! - Quadrantes");
    else
        printf("\nSUDOKU INVALIDO!");

    return 0;
}