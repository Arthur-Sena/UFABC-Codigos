#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaPar(char *texto, int i)
{
    int chaves = 1;

    if (texto[i] == '{')
    {
        for (i++; chaves > 0 && i < strlen(texto); i++)
        {
            if (texto[i] == '{')
                chaves++;
            if (texto[i] == '}')
                chaves--;
            if (chaves == 0)
            {
                // printf("par de { em %d\n", i);
                return i;
            }
        }
    }

    if (texto[i] == '}')
    {
        for (i--; chaves > 0 && i >= 0; i--)
        {
            if (texto[i] == '}')
                chaves++;
            if (texto[i] == '{')
                chaves--;
            if (chaves == 0)
            {
                // printf("par de } em %d\n", i);
                return i;
            }
        }
    }

    // printf("par de { ou } não encontrado\n");
    return -1;
}

int main()
{
    int N;
    scanf("%d%*c", &N);

    char linhas[N][110];

    int tamanhoTotal = 0;

    for (int i = 0; i < N; i++)
    {
        fgets(linhas[i], 110, stdin);
        tamanhoTotal += strlen(linhas[i]);
    }

    char *codigoCompleto = (char *)malloc((tamanhoTotal + 1) * sizeof(char));
    codigoCompleto[0] = '\0';

    for (int i = 0; i < N; i++)
        strcat(codigoCompleto, linhas[i]);

    // printf("%s\n", codigoCompleto);

    int ehValido = 1;

    int i = 0;
    int fim = strlen(codigoCompleto);

    while (i < fim && ehValido)
    {
        if (codigoCompleto[i] == '{' || codigoCompleto[i] == '}')
            if (buscaPar(codigoCompleto, i) == -1)
                ehValido = 0;
        i++;
    }

    printf("%s\n", ehValido ? "S" : "N");

    return 0;
}