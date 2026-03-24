#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);

    double delta = B * B - 4 * A * C;

    if (delta > 0) {
        double raiz1 = (-B + sqrt(delta)) / (2 * A);
        double raiz2 = (-B - sqrt(delta)) / (2 * A);
        printf("%.4lf %.4lf\n", raiz1, raiz2);
    } else if (delta == 0) {
        double raiz = -B / (2 * A);
        printf("%.4lf\n", raiz);
    } else {
        printf("nao ha raiz real\n");
    }

    return 0;
}