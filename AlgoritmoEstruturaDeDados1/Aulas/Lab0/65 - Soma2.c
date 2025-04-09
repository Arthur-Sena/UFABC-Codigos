#include <stdio.h>

int main()
{
    int N, x, soma = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        soma += x;
    }

    printf("%d\n", soma);
}