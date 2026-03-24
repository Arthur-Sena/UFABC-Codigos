#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int M1, M2;
        scanf("%d %d", &M1, &M2);

        if (M2 >= 0 && M2 <= 2)
            printf("Nova");

        if (M2 >= 97 && M2 <= 100)
            printf("Cheia");

        if (M2 > 2 && M2 < 97)
            printf(M2 > M1 ? "Crescente" : "Minguante");

        printf("\n");
    }
    return 0;
}