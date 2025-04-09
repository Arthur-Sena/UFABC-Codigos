// Arthur Sena
#include <stdio.h>

//Busca Linear O(n)
int main()
{

    // Preenche o vetor com os números de 0 a 100
    int vetor[101];
    for (int i = 0; i <= 100; i++) 
        vetor[i] = i;   
    
    int tamanhoVetor = (long)sizeof(vetor) / (long)sizeof(vetor[0]);
    
    printf("Digite um valor: ");
    int valorBuscado; 
    scanf("%d", &valorBuscado);

    for (int i = 0; i < tamanhoVetor; i++)
        if (vetor[i] == valorBuscado)
        {
            printf("Valor %d encontrado em %d repeticoes", vetor[i], i);
            return 0;
        }

    printf("Valor nao encontrado");
    return 0;
}