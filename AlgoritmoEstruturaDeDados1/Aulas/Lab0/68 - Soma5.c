#include <stdio.h>

int main()
{
    int x = 0;
    long long soma = 0;

    do {
        scanf("%d", &x);
        soma += x;
    } while (x != 0);

    printf("%lld\n", soma);

    return 0;
}