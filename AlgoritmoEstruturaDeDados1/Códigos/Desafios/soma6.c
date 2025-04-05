#include <stdio.h>

int main() {
    long num, soma = 0;

    while (scanf("%ld", &num) == 1 && num != 0)
        soma += num;

    printf("%d\n", soma);
    return 0;
}