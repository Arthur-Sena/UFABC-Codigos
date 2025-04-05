#include <stdio.h>
#include <stdlib.h>

void preencheLista(int* lista, int qntElemtos)
{
    for (int i = 0; i < qntElemtos; i++)
        scanf("%d", &lista[i]);
}

void imprimeElementosExcluidos(int* lista, int inicioExcluido, int fimExluido)
{
    for (int i = inicioExcluido; i <= fimExluido; i++)
        if(i == fimExluido)
            printf("%d\n",lista[i]);
        else
            printf("%d ", lista[i]);
}

void buscaBinaria(int* lista, int qntElementos, int elemBuscado)
{
    int inicioBusca = 0, fimBusca = qntElementos-1, meioBusca;
    while (inicioBusca <= fimBusca)
    {
        meioBusca = (inicioBusca + fimBusca) / 2;
        if (lista[meioBusca] == elemBuscado)
        {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", elemBuscado);
            return;
        }
        else if (elemBuscado < lista[meioBusca])
        {
            imprimeElementosExcluidos(lista, meioBusca, fimBusca);
            fimBusca = meioBusca - 1;
        }
        else
        {
            imprimeElementosExcluidos(lista, inicioBusca, meioBusca);
            inicioBusca = meioBusca + 1;
        }
    }
    printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", elemBuscado);
}

int main()
{
    int qntElemtos, elemBuscado;
    scanf("%d", &qntElemtos);

    int* lista = (int*) malloc(qntElemtos * sizeof(int));
    preencheLista(lista, qntElemtos);

    while(scanf("%d", &elemBuscado) != EOF)
        buscaBinaria(lista, qntElemtos, elemBuscado);

    free(lista);
    return 0;
}