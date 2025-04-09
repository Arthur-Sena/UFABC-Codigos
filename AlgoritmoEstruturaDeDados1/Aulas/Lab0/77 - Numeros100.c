#include <stdio.h>

int main()
{
    int x = 0;
    
    while (x < 101)
    {
        if (x > 0)
            printf(" ");
        printf("%d", x);
        x++;
    }
    printf("\n");

    return 0;
}