#include <stdio.h>

int anoEhBissexto(int ano) {
    if (((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) && ano >= 1582 && ano <= 100000)
        return 1;

    return 0;
}

int dataEhValida(int dia, int mes, int ano) {
    if (ano < 1582 || (ano == 1582 && mes < 10) || (ano == 1582 && mes == 10 && dia < 15)) {
        return 0;
    }
    if (mes < 1 || mes > 12) {
        return 0;
    }
    if (dia < 1) {
        return 0;
    }

    int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (anoEhBissexto(ano)) {
        diasNoMes[1] = 29;
    }
    if (dia > diasNoMes[mes - 1]) {
        return 0;
    }
    return 1;
}

int main() {
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    if (dataEhValida(dia, mes, ano)) {
        printf("DATA VALIDA\n");
    } else {
        printf("DATA INVALIDA\n");
    }

    return 0;
}