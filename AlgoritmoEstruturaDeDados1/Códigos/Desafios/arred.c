#include <stdio.h>

int main(){
    long num;

    scanf("%ld", &num);
    printf("%ld.0000\n", num + 1);
    return 0;
}