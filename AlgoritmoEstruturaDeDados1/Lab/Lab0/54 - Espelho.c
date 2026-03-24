#include <stdio.h>

int espelhar(int n) {
    int espelhado = 0;
    while (n != 0) {
        espelhado = espelhado * 10 + n % 10;
        n /= 10;
    }
    return espelhado;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    if (espelhar(A) == B) {
        printf("espelho\n");
    } else {
        printf("nao espelho\n");
    }

    return 0;
}