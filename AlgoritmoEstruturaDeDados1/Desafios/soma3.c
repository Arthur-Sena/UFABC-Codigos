#include <stdio.h>

int main() {
    long num, soma = 0;

    while (scanf("%ld", &num) != EOF)
        soma += num;

    printf("%ld\n", soma);
    return 0;
}