#include <stdio.h>

int ehPrimo(long int N)
{
    if (N <= 1)
        return 0;
    int i = 2;
    while (i <= N / 2)
    {
        if (N % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    long int N;
    while (scanf("%ld", &N) && N >= 0)
        printf(ehPrimo(N) ? "SIM\n" : "NAO\n");

    return 0;
}