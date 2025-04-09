#include <stdio.h>

int main()
{
    int N1, N2;

    scanf("%d", &N1);
    char S1[N1 + 1];
    scanf("%s", S1);

    scanf("%d", &N2);
    char S2[N2 + 1];
    scanf("%s", S2);

    char Sr[N1 + N2 + 1];

    int i1 = 0;
    int i2 = 0;
    int ir = 0;

    while (i1 < N1 && i2 < N2)
        if (S1[i1] <= S2[i2])
            Sr[ir++] = S1[i1++];
        else
            Sr[ir++] = S2[i2++];

    while (i1 < N1)
        Sr[ir++] = S1[i1++];

    while (i2 < N2)
        Sr[ir++] = S2[i2++];

    Sr[ir] = '\0';
    printf("%s\n", Sr);

    return 0;
}