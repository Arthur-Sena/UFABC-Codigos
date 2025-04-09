
#include <stdio.h>

int main()
{
    long int X, Y;
    scanf("%ld %ld", &X, &Y);

    if (X % Y == 0)
    {
        printf("a divisao de %ld por %ld eh exata.\n", X, Y);
    }

    return 0;
}