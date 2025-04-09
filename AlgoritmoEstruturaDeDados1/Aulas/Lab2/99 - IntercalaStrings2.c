#include <stdio.h>

int main()
{
    char S[20001];
    char R[20001];
    int N, M;

    scanf("%s", S);
    scanf("%d %d", &N, &M);

    int iE = 0;
    int fE = N - 1;
    int iD = N;
    int fD = N + M - 1;
    int iR = 0;

    while (iE <= fE && iD <= fD)
        if (S[iE] <= S[iD])
            R[iR++] = S[iE++];
        else
            R[iR++] = S[iD++];

    while (iE <= fE)
        R[iR++] = S[iE++];

    while (iD <= fD)
        R[iR++] = S[iD++];

    R[iR] = '\0';
    printf("%s\n", R);

    return 0;
}