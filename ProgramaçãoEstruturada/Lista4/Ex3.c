/*Questão 3. Escreva um programa que converte os caracteres maiúsculos de uma string em minúsculos e vice-versa. Suponha que só há caracteres latinos sem acentos.*/

#include <stdio.h>
#include <string.h>
 
#define MAX 99999

int main() {
    char frase[MAX];

    printf("Digite a frase: ");
    fgets(frase, MAX, stdin);
    
    printf("Saida: ");
    	
    for (int i = 0; i < strlen(frase); i++)
    	if (frase[i] >= 97 && frase[i] <= 122)
    		printf("%c", (frase[i] - 32));
    	else if (frase[i] >= 65 && frase[i] <= 90)
    		printf("%c", (frase[i] + 32));
    	else
    		printf("%c", frase[i]);
	
	printf("\n");
    return 0;
}