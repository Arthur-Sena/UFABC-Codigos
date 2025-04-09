#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int M;
        scanf("%d", &M);

        long int x;
        long long soma = 0;
        for (int j = 0; j < M; j++)
        {
            scanf("%ld", &x);
            soma += x;
        }
        printf("%lld\n", soma);
    }
}