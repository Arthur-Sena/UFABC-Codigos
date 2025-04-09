#include <stdio.h>
#include <string.h>

int main()
{
    char u[50];
    int a;
    printf("Onde voce estuda: ");
    scanf("%50s", u);
    printf("Quanto tempo: ");
    scanf("%d", &a);
    printf("Voce estuda na %s ha %d anos.\n", u, a);
    return 0;
}