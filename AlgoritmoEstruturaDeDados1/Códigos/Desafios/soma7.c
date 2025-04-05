#include <stdio.h>

int main() {
    long num, soma = 0;

    while (scanf("%ld", &num) != EOF)
    {
        if (num == 0)
        {
            printf("%d\n", soma);
            soma = 0;
            continue;
        }
        soma += num;
    }

    return 0;
}