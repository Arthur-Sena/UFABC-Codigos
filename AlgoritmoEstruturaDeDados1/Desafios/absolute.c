#include <stdio.h>

int main() {
    long num, abs;
    scanf("%ld", &num);

    abs = num < 0 ? num * -1 : num;
    printf("%ld\n", abs);
    return 0;
}