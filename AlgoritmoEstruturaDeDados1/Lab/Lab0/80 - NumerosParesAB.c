#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    if (A <= B)
        if (A % 2 == 0)
            printf("%d", A++);
        else
            printf("%d", ++A);
        A++;

    while (A <= B)
    {
        if (A % 2 == 0)
            printf(" %d", A++);
        A++;
    }
    printf("\n");

    return 0;
}