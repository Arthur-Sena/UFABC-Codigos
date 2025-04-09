#include <stdio.h>

int main()
{
    char N[100];
    char M[12];
    char nomicula[111];

    while (scanf("%s %s", N, M) != EOF)
    {
        int iP = 0;
        int iN = 0;
        int iM = 0;

        while (N[iN] != '\0' || M[iM] != '\0')
        {
            if (N[iN] != '\0')
            {
                nomicula[iP] = N[iN];
                iP++;
                iN++;
            }
            if (M[iM] != '\0')
            {
                nomicula[iP] = M[iM];
                iP++;
                iM++;
            }
            if (N[iN] == '\0' && M[iM] == '\0')
            {
                nomicula[iP] = '\0';
                printf("%s\n", nomicula);
            }
        }
    }

    return 0;
}