#include <stdio.h>

int main() {
    long int A, B;

    scanf("%ld %ld", &A, &B);

    printf("%s\n", A < B ? "true" : "false");

    return 0;
}