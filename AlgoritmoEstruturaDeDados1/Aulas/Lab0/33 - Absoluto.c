#include <stdio.h>

int main()
{
    long int X;
    scanf("%ld", &X);
    printf("%ld\n", X < 0 ? X * -1 : X);
    return 0;
}