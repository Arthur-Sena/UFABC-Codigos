#include <stdio.h>

int main() {
    long num, totalSoma = 0;
    
    while (1)
    {
        scanf("%ld", &num);
        if (num == 0)
            break;
            
        totalSoma += num;
    }

    printf("%ld\n", totalSoma);
    return 0;
}