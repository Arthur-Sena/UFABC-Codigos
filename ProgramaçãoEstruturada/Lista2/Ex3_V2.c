#include <stdio.h>

void ordena(int valores[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (valores[i] > valores[j]) {
                temp = valores[i];
                valores[i] = valores[j];
                valores[j] = temp;
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

    int valores[n];

    printf("Digite %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nDigite o %dº valor da lista: ", i + 1);
        scanf("%d", &valores[i]);
    }

    ordena(valores, n);

    printf("Números em ordem não decrescente:\n");
    for (int i = 0; i < n; i++) 
        printf("%d ", valores[i]);
    
    printf("\n");

    return 0;
}