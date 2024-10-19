//Lista 1 - Ex 7
#include <stdio.h>

int main(){

        int i, f;
        printf("Digite o primeiro número: (Menor que o próximo)\n");
        scanf("%d", &i);
        printf("Digite o segundo número:\n");
        scanf("%d", &f);

        if(i>=f){
                printf("O primeiro número deverá ser menor que o segundo.\n");
                return 0;
        }

        printf("Numeros primos entre [%d, %d]\n", i, f);

        for(int j = i; j <= f; j++){
                if(j == 2 || j == 3 || j == 5 || j == 7){
                        printf("%d\n", j);
                } else {
                        if(j%2 != 0 && j%3 != 0 && j%5 != 0 && j%7 != 0 && j%1 == 0 && j%j == 0){
                                printf("%d\n", j);
                        }
                }
        }

        return 0;
}