// Arthur Sena
#include <stdio.h>

// Busca binaria O(log(n))
int main()
{
    int vetor[101];

    // Preenche o vetor com os números de 0 a 100
    for (int i = 0; i <= 100; i++) 
        vetor[i] = i;    

    printf("Digite o numero buscado: ");
    int numBuscado; scanf("%d", &numBuscado);

    int tamanhoVetor = sizeof(vetor) / sizeof(vetor[0]);
    int numRep = 0, esq = 0, dir = tamanhoVetor, meio;
    while (esq <= dir)
    {
        numRep++;
        meio = (esq + dir) / 2;
        
        if (vetor[meio] == numBuscado)
        {
            printf("Busca conculida em %d repeticoes", numRep);
            return meio;
        }
        else if (vetor[meio] > numBuscado)
            dir = meio - 1;
        else
            esq = meio + 1;
    }
    return -1;
}