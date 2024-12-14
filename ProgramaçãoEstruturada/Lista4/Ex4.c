/*Questão 4. Escreva um programa que receba uma palavra e uma frase como entrada. O programa
deve escrever “sim” se a palavra estiver presente na frase e “não” caso contrário.*/

#include <stdio.h>
#include <string.h>
 
#define MAX 99999

int main() {
    char palavra[MAX], frase[MAX];

    printf("Digite a frase: ");
    fgets(frase, MAX, stdin);
    
    printf("Digite a palavra: ");
    fgets(palavra, MAX, stdin);
        	
    if (strstr(frase, palavra))
		printf("Sim \n");
	else
		printf("Nao \n");
    return 0;
}