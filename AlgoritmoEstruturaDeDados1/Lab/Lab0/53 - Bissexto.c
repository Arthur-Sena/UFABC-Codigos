// São bissextos todos os anos múltiplos de 400, p.ex: 1600, 2000, 2400, 2800.
// São bissextos todos os múltiplos de 4 e não múltiplos de 100, p.ex: 1996, 2004, 2008, 2012

#include <stdio.h>

int main()
{
    long int ano;
    scanf("%ld", &ano);

    if (((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) && ano >= 1582 && ano <= 100000)
    {
        printf("ANO BISSEXTO\n");
    }
    else 
    {
        printf("ANO NAO BISSEXTO\n");
    }

    return 0;
}