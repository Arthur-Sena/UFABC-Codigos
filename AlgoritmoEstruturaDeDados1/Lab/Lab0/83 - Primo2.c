#include <stdio.h>

int main() {
    int S, F;
    scanf("%d %d", &S, &F);

    printf("Primos entre %d e %d:", S, F);

    int i = S < 2 ? 2 : S;

    while (i <= F) {
        int ehComposto = 0;

        for (int j = 2; j <= i / 2 && !ehComposto; j++)
            if (i % j == 0)
                ehComposto = 1;

        if (!ehComposto)
            printf(" %d", i);

        i++;
    }
    printf("\n");

    return 0;
}