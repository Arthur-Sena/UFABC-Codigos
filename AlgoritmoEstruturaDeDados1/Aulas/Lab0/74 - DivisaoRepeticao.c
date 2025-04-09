#include <stdio.h>

int main()
{
    int A, B, Q = 0;
    scanf("%d %d", &A, &B);

    while (A >= B)
    {
        A -= B;
        Q++;
    }

    printf("%d\n", Q);

    return 0;
}