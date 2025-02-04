//Lista 5 Questão 1. Escreva um programa que, dado um inteiro n fornecido pelo usuário, leia n números
//inteiros fornecidos pelo usuário e compute a média desses números.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanhoN;

    printf("Digite um n: ");
    scanf("%d", &tamanhoN);
    

    int* v = (int*)malloc(5 * sizeof(int));
    int total = 0;
    for (int i = 1; i <= tamanhoN; i++){
        printf("\nDigite a nota %d: ", i);
        scanf("%d", &v[i-1]);
        total += v[i-1];
    }
        
    printf("Media: %lf \n", (total / (double)tamanhoN)); 

    //Liberando memória
    for (int i = 0; i <= tamanhoN; i++)
        free(&v[i]);
    return 0;
}