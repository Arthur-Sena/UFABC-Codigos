#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    
    printf("%d", A++);
    while (A <= B)
        printf(" %d", A++);
    printf("\n");

    return 0;
}