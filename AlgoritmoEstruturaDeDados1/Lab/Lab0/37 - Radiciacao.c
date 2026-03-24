#include <stdio.h>
#include <math.h>

int main() {
    long int A;

    scanf("%ld", &A);

    printf("%.4f\n", (double) pow(A, 0.5));

    return 0;
}