#include <stdio.h>

char* quadrante(double X, double Y) {
    if (X == 0 && Y == 0) return "Origem"; 
    if (X == 0)           return "Eixo Y";
    if (Y == 0)           return "Eixo X";
    if (X > 0 && Y > 0)   return "Q1";
    if (X < 0 && Y > 0)   return "Q2";
    if (X < 0 && Y < 0)   return "Q3";
    if (X > 0 && Y < 0)   return "Q4";

    return "Erro";
}

int main () {
    double X, Y;

    scanf("%lf %lf", &X, &Y);

    printf("%s\n", quadrante(X, Y));

    return 0;
}