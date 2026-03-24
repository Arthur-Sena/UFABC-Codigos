#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    long int F = 1;

    while (N > 1)
    {
        F *= N;
        N--;
    }

    printf("%ld\n", F);

    return 0;
}