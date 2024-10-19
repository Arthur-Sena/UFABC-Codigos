//Lista 1 - Ex 4

#include <stdio.h>

int fatorial(int value){
        int ret = 1;
        for(int i = 1; i <= value; i++)
                ret *= i;
        return ret;
}

int main(){
        int n, k;
        printf("insira o valor de N:\n");
        scanf("%d", &n);
        printf("insira o valor de K:\n");
        scanf("%d", &k);

        int fatN, fatK, fatNMinusK;
        fatN = fatorial(n);
        fatK = fatorial(k);
        fatNMinusK = fatorial(n-k);
        int res = (fatN/fatK*(fatNMinusK));
        printf("Resultado: %d", res);
        return 0;
}