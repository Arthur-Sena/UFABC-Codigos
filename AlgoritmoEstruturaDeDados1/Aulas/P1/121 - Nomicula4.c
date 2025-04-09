#include <stdio.h>

int main()
{
    char nome[100], matricula[12], nomicula[111];

    while (scanf("%s %s", nome, matricula) != EOF)
    {
        int p = 0, n = 0, m = 0;

        while (nome[n] != '\0' || matricula[m] != '\0')
        {
            for (int i = 0; i < 3 && nome[n] != '\0'; i++)
                nomicula[p++] = nome[n++];

            for (int i = 0; i < 3 && matricula[m] != '\0'; i++)
                nomicula[p++] = matricula[m++];
        }

        nomicula[p] = '\0';
        printf("%s\n", nomicula);
    }

    return 0;
}