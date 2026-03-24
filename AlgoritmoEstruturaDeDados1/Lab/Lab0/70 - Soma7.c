#include <stdio.h>

int main() {
    long int x;
    long long int soma;

    while (scanf("%ld", &x) != EOF) {
        soma = 0;

        while (x != 0) {
            soma += x;
            scanf("%ld", &x);
        }

        printf("%lld\n", soma);
    }

    return 0;
}