#include <stdio.h>

int main() {
    long int x;
    long long int soma = 0;

    while (scanf("%ld", &x) && x != 0) {
        soma += x;
    }

    printf("%lld\n", soma);

    return 0;
}