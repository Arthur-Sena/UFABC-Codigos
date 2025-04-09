#include <stdio.h>
#include <math.h>

int main() {
    int A, N;

    scanf("%d %d", &A, &N);

    printf("%.4f\n", (double) pow(A, N));

    return 0;
}