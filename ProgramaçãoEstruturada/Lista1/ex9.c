//Lista 1 - Ex 9

#include <stdio.h>

void produto_hadamard(double u[], double v[], int tamanho){
        double matrizHadamard[10000];

         for(int i = 0; i < tamanho; i++){
                 matrizHadamard[i] = u[i]*v[i];
         }

         printf("MATRIZ HADAMARD\n");
         for(int j = 0; j < tamanho; j++){
                 printf("%lf\n", matrizHadamard[j]);
         }
}

int main(){
        int tmV;

        printf("Entre com o tamanho dos vetores:\n");
        scanf("%d", &tmV);

        double u[10000], v[10000];

        for(int qu = 0; qu < tmV; qu++){
                printf("Entre com o %dº Valor da Primeira Matriz:\n", qu+1);
                scanf("%lf", &u[qu]);
        }

        for(int qv = 0; qv < tmV; qv++){
                printf("Entre com o %dº Valor da Segunda Matriz:\n", qv+1);
                scanf("%lf", &v[qv]);
        }

        produto_hadamard(u, v, tmV);

        return 0;
}
