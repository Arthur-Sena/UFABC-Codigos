#include <stdio.h>

int main()
{

    int q1, q2;
    scanf("%d", &q1);
    scanf("%d", &q2);

    int v1[q1], v2[q2], vR[q1 + q2];

    for (int i = 0; i < q1; i++)
        scanf("%d", &v1[i]);

    for (int i = 0; i < q2; i++)
        scanf("%d", &v2[i]);

    int i1 = 0, i2 = 0, iR = 0;

    while (i1 < q1 && i2 < q2)
    {
        if (v1[i1] <= v2[i2])
            vR[iR++] = v1[i1++];
        else
            vR[iR++] = v2[i2++];
    }

    while (i1 < q1)
        vR[iR++] = v1[i1++];

    while (i2 < q2)
        vR[iR++] = v2[i2++];

    for (int i = 0; i < q1 + q2; i++)
        printf("%d\n", vR[i]);

    return 0;
}