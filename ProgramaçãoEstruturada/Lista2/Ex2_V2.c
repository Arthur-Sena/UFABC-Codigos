#include <stdio.h>

void ordenarDecrescente(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int n;

    printf("Digite a quantidade de números (1 ≤ n ≤ 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Número inválido! n deve estar entre 1 e 100.\n");
        return 1;
    }

    int numeros[n];

    printf("Digite %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nDigite o %dº valor da lista: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    ordenarDecrescente(numeros, n);

    printf("Números em ordem não crescente:\n");
    for (int i = 0; i < n; i++) 
        printf("%d, ", numeros[i]);
    
    return 0;
}