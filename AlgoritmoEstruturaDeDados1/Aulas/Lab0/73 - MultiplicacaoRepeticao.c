#include <stdio.h>

int main()
{
    int A, B, P = 0;
    scanf("%d %d", &A, &B);

    while (B > 0)
    {   
        P += A;
        B--;
    }

    printf("%d\n", P);

    return 0;
}