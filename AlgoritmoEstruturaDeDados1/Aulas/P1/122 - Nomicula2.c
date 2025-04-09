#include <stdio.h>

int main()
{
    char nome[100], matricula[12], nomicula[111];

    while (scanf("%s %s", nome, matricula) != EOF)
    {
        int p = 0, n = 0, m = 0;

        while (nome[n] != '\0' || matricula[m] != '\0')
        {
            nome[n] != '\0' ? nomicula[p++] = nome[n++] : 0;
            nome[n] != '\0' ? nomicula[p++] = nome[n++] : 0;
            
            matricula[m] != '\0' ? nomicula[p++] = matricula[m++] : 0;
            matricula[m] != '\0' ? nomicula[p++] = matricula[m++] : 0;
        }

        nomicula[p] = '\0';
        printf("%s\n", nomicula);
    }

    return 0;
}