#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    while (A >= B)
        A -= B;

    printf("%d\n", A);

    return 0;
}