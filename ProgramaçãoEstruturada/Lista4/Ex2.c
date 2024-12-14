/*Questão 2. Escreva um programa que devolva o tamanho da maior cadeia de 0’s de uma string*/

#include <stdio.h>
#include <string.h>
 
#define MAX 99999

int main() {
    char binario[MAX];

    printf("Digite a frase: ");
    fgets(binario, MAX, stdin);
    
	int maiorSequencia = 0, sequenciaAtual = 0;    
    for (int i = 0; i < strlen(binario); i++)
    	if (binario[i] == '0')
    		sequenciaAtual += 1;
    	else
    	{ 
    		if (sequenciaAtual > maiorSequencia)
	    		maiorSequencia = sequenciaAtual;
    		sequenciaAtual = 0;	
		}
		
    printf("Saida: %d", maiorSequencia);
	printf("\n");
    return 0;
}