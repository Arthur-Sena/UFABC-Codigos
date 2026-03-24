#include <stdio.h>

char* classificarImc(double imc) {
    if (imc < 16.0) return "Magreza grave"; 
    if (imc < 17.0) return "Magreza moderada"; 
    if (imc < 18.5) return "Magreza leve"; 
    if (imc < 25.0) return "Saudavel"; 
    if (imc < 30.0) return "Sobrepeso"; 
    if (imc < 35.0) return "Obesidade Grau I"; 
    if (imc < 40.0) return "Obesidade Grau II (severa)"; 
    if (imc >= 40)  return "Obesidade Grau III (morbida)";
}

int main () {
    double peso, altura, imc;

    scanf("%lf %lf", &altura, &peso);

    imc = peso / (altura * altura);

    printf("%s\n", classificarImc(imc));

    return 0;
}