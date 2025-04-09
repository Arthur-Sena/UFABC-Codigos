#include <stdio.h>

int main ()
{
    int idade1, idade2;
    scanf("%d %d", &idade1, &idade2);
    printf("%d\n", idade1 > idade2 ? idade1 : idade2);
    return 0;
}