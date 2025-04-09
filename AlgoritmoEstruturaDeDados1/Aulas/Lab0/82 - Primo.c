#include <stdio.h>

int main()
{
    long int K;
    scanf("%ld", &K);

    int ehComposto = 0;
    for (int i = 2; i <= K / 2 && !ehComposto; i++)
        if (K % i == 0)
            ehComposto = 1;

    if (ehComposto || K == 1)
        printf("COMPOSTO\n");
    else
        printf("PRIMO\n");

    return 0;
}