#include <stdio.h>

int main(){
        int v[1000][1000];
        int n, m;
        int ia, ja;

        printf("Digite a quantidade de Linhas - (entre 1 e 1000):\n");
        scanf("%d", &n);

        printf("Digite o quantidade de Colunas - (entre 1 e 1000):\n");
        scanf("%d", &m);

        if((n < 1 || n > 1000) || (m < 1 || m > 1000)){
            printf("tamanho da matriz incorreto!");
            return 0;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                printf("\nMATRIZ - Digite o valor da posição {%d, %d}:", i+1, j+1);
                scanf("%d", &v[i][j]);
            }
        }

        printf("\n\nMatriz INICIAL\n");
        for(int k = 0; k < n; k++){
            printf("Linha %d: ", k+1);
            for(int l = 0; l < m; l++){
                if(l == m-1){
                    printf("%d ", v[k][l]);
                } else {
                    printf("%d, ", v[k][l]);
                }
            }
            printf("\n");
        }

        printf("\nDigite um inteiro - (entre 1 e %d):\n", n);
        scanf("%d", &ia);
        ia -= 1;

        printf("Digite outro inteiro - (entre 1 e %d):\n", n);
        scanf("%d", &ja);
        ja -= 1;

        printf("\nMatriz FINAL ...\n");
        for(int k = 0; k < n; k++){
            int lu = k;
            if(k == ia)
                lu = ja;
            if(k == ja)
                lu = ia;
            if(k != lu){
                printf("Linha %d->%d: ", k+1, lu+1);
            } else {
                printf("Linha CC %d: ", k+1);
            }
            for(int l = 0; l < m; l++){
                if(l == m-1){
                    printf("%d ", v[lu][l]);
                } else {
                    printf("%d, ", v[lu][l]);
                }
            }
            printf("\n");
        }

        return 0;
}