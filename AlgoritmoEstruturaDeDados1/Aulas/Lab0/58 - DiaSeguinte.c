#include <stdio.h>

int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int anoEhBissexto(int ano)
{
    if (((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) && ano >= 1582 && ano <= 100000)
        return 1;
    return 0;
}

void diaSeguinte(int *dia, int *mes, int *ano)
{
    if (anoEhBissexto(*ano))
    {
        diasNoMes[1] = 29;
    }

    (*dia)++;
    if (*dia > diasNoMes[*mes - 1])
    {
        *dia = 1;
        (*mes)++;
        if (*mes > 12)
        {
            *mes = 1;
            (*ano)++;
        }
    }
}

int main()
{
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);

    diaSeguinte(&dia, &mes, &ano);

    printf("%02d %02d %04d\n", dia, mes, ano);

    return 0;
}