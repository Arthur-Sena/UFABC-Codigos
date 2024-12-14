//Lista 5 Questão 1. Escreva um programa que, dado um inteiro n fornecido pelo usuário, leia n números
//inteiros fornecidos pelo usuário e compute a média desses números.

#include <stdio.h>

int main() {
    int tamanhoN;

    printf("Digite um n: ");
    scanf("%d", tamanhoN);
    
    int* v = malloc(tamanhoN * sizeof(int));

    for (int i = 0; i < tamanhoN; i++)
        scanf("%d", &v[i]);
        
    int total = 0;
    for (int i = 0; i < tamanhoN; i++)
        total += v[i];
        
    printf("Media: %lf\n", total / (double) n); 
    return 0;
}