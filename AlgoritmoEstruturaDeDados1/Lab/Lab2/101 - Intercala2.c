#include <stdio.h>

int main()
{

    int q1, q2;
    scanf("%d", &q1);
    scanf("%d", &q2);

    int vI[q1 + q2], vF[q1 + q2];

    for (int i = 0; i < q1; i++)
        scanf("%d", &vI[i]);

    for (int i = q1; i < q1 + q2; i++)
        scanf("%d", &vI[i]);

    int iE = 0, iD = q1, iF = 0;

    while (iE < q1 && iD < q1 + q2)
    {
        if (vI[iE] <= vI[iD])
            vF[iF++] = vI[iE++];
        else
            vF[iF++] = vI[iD++];
    }

    while (iE < q1)
        vF[iF++] = vI[iE++];

    while (iD < q1 + q2)
        vF[iF++] = vI[iD++];

    for (int i = 0; i < q1 + q2; i++)
        printf("%d\n", vF[i]);

    return 0;
}