#include <stdio.h>

int main()
{
    int M1, M2;
    scanf("%d %d", &M1, &M2);

    if (M2 >= 0 && M2 <= 2)
    {
        printf("Nova\n");
    }
    if (M2 > 2 && M2 < 97)
    {
        if (M2 > M1)
        {
            printf("Crescente\n");
        }
        else
        {
            printf("Minguante\n");
        }
    }
    if (M2 >= 97 && M2 <= 100)
    {
        printf("Cheia\n");
    }

    return 0;
}