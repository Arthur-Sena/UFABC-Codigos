/*Questão 1. Escreva um programa que recebe um caractere e uma frase e imprima a frase fornecida
até a primeira ocorrência do caractere fornecido. O seu programa funciona corretamente mesmo que
o caractere fornecido não apareça na frase? Veja o exemplo abaixo.*/

#include <stdio.h>
#include <string.h>
 
#define MAX 99999

int main() {
    char caractere, frase[MAX];

    printf("Digite a frase: ");
    fgets(frase, MAX, stdin);
    
    printf("Digite o caractere: ");
    scanf("%c", &caractere);
    
    printf("Saida: ");
    for (int i = 0; i < strlen(frase); i++)
    	if (frase[i] != caractere)
    		printf("%c", frase[i]);
    	else
    		break;	
	
	printf("\n");
    return 0;
}