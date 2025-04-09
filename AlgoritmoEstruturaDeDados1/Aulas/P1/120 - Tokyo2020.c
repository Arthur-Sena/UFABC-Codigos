#include <stdio.h>
#include <string.h>

int N; // quantidade de paises

typedef struct
{
    char nome[101];
    int ouro;
    int prata;
    int bronze;
} Pais;

void montarTabela(Pais paises[])
{
    for (int i = 0; i < N; i++)
        scanf("%s %d %d %d",
              paises[i].nome,
              &paises[i].ouro,
              &paises[i].prata,
              &paises[i].bronze);
}

void trocaPaises(Pais *a, Pais *b)
{
    Pais temp = *a;
    *a = *b;
    *b = temp;
}

int compararPaises(Pais a, Pais b)
{
    if (a.ouro != b.ouro)
        return b.ouro - a.ouro;

    if (a.prata != b.prata)
        return b.prata - a.prata;

    if (a.bronze != b.bronze)
        return b.bronze - a.bronze;

    return strcmp(a.nome, b.nome);
}

void classificarTabela(Pais paises[])
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)

            if (compararPaises(paises[i], paises[j]) > 0)
                trocaPaises(&paises[i], &paises[j]);
}

void imprimirTabela(Pais paises[])
{
    for (int i = 0; i < N; i++)
        printf("%s %d %d %d\n",
               paises[i].nome,
               paises[i].ouro,
               paises[i].prata,
               paises[i].bronze);
}

int main()
{
    scanf("%d", &N);

    Pais paises[N];

    montarTabela(paises);
    classificarTabela(paises);
    imprimirTabela(paises);

    return 0;
}
