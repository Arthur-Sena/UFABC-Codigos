#include <stdio.h>

int main()
{
    int N;

    while (scanf("%d", &N) && N != 0) {

        int vetor[N];
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &vetor[i]);
        }

        int maior = vetor[0];
        int indice = 0;
        for (int i = 1; i < N; i++) {
            if (vetor[i] > maior) {
                maior = vetor[i];
                indice = i;
            }
        }

        printf("%d %d\n", indice, maior);
    }

    return 0;
}