#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int iPar = A;
    int iImpar = A;
    A % 2 == 0 ? iImpar++ : iPar++;

    if (iPar <= B)
        printf("%d", iPar++);
    while (iPar <= B)
    {
        if (iPar % 2 == 0)
            printf(" %d", iPar++);
        iPar++;
    }
    printf("\n");

    if (iImpar <= B)
        printf("%d", iImpar++);
    while (iImpar <= B)
    {
        if (iImpar % 2 != 0)
            printf(" %d", iImpar++);
        iImpar++;
    }
    printf("\n");

    return 0;
}