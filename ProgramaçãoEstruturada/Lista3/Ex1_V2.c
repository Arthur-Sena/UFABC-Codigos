#include <stdio.h>

long busca_binaria(long vetor[], long n, long chave) {
    long inicio = 0;
    long fim = n - 1;
    
    while (inicio < fim) {
        long meio = (inicio + fim) / 2;

        if (chave <= vetor[meio]) 
            fim = meio;
        else 
            inicio = meio + 1;        
    }

    if (vetor[inicio] == chave) 
        return inicio;

    return -1;
}

int main() {
    long vetor[1000];
    long n, chave;
    printf("Digite o tamanho do vetor: ");
    scanf("%ld", &n);

    printf("Inicialização do Vetor (digitar em ordem crescente) :\n");
    for (long i = 0; i < n; i++)
    {
        printf("\nVETOR - Digite o valor da posição %ld° :", i + 1);
        scanf("%ld", &vetor[i]);
        if (i > 0 && vetor[i] < vetor[i - 1])
        {
            printf("\n - WARNING - Digite novamente o valor da posição %ld° :", i + 1);
            scanf("%ld", &vetor[i]);
        }
    }

    printf("Digite o valor da chave: ");
    scanf("%ld", &chave);
    
    long resultado = busca_binaria(vetor, n, chave);
    if (resultado != -1)
        printf("Chave encontrada na posição: %ld ", resultado);
    else 
        printf("Chave não encontrada no vetor.\n");
    
    return 0;
}