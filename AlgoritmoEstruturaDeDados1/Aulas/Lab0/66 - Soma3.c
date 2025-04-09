#include <stdio.h>

int main() {
    int x, soma = 0;

    while (scanf("%d", &x) != EOF) {
        soma += x;
    }

    printf("%d\n", soma);

    return 0;
}