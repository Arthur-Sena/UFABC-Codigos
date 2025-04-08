#include<stdio.h>
#include<stdlib.h>

struct tFila
{
    int *itens;
    int tamanho;
    int inicio;
    int final;
};

int primeiro(struct tFila f)
{
    return f.itens[f.inicio];
}

int ultimo(struct tFila f)
{
    int iUltimo = f.final - 1;
    if(iUltimo == -1)
    {
        iUltimo = f.tamanho - 1;
    }
    return f.itens[iUltimo];
}

int filaCheia(struct tFila f)
{
    return (f.final + 1) % f.tamanho == f.inicio;
}

int filaVazia(struct tFila f)
{
    return f.inicio == f.final;
}

void desenfileirar(struct tFila *f)
{
    if(!filaVazia(*f))
    {
        f->inicio = (f->inicio + 1) % f->tamanho;
    }
}

void enfileirar(struct tFila *f, int novo)
{
    if(!filaCheia(*f))
    {
        f->itens[f->final] = novo;
        f->final = (f->final + 1) % f->tamanho;
    }
}

void mostrarFila(struct tFila f)
{
    int i;
    for(i = f.inicio; i != f.final; i = (i + 1) % f.tamanho)
    {
        printf("%d%s", f.itens[i], f.itens[i] != ultimo(f)?" ":"\n");
    }
}
/* CONDICAO DE PARADA i%f.tamanho != f.final */


struct tFila criarFila(int n)
{
    struct tFila f;
    f.itens = (int *) malloc(n * sizeof(int));
    f.tamanho = n;
    f.inicio = 0;
    f.final = 0;

    return f;
}

int main()
{
    int opc, n, chave;
    struct tFila fila;

    scanf("%d", &n);
    fila = criarFila(n);

    do
    {
        do
        {
            printf("Escolha uma das opcoes a seguir:\n");
            printf("1 - Enfileirar\n");
            printf("2 - Mostrar Fila\n");
            printf("3 - Primeiro da Fila\n");
            printf("4 - Ultima da Fila\n");
            printf("5 - Desenfileirar\n");
            printf("6 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        }while(opc < 1 || opc > 6);

        switch(opc)
        {
            case 1: printf("Informe o valor da chave: ");
                    scanf("%d", &chave);
                    enfileirar(&fila, chave);
                    break;
            case 2: mostrarFila(fila);
                    break;
            case 3: if(!filaVazia(fila))
                    {
                        printf("Item [%d] eh o primeiro da fila\n", primeiro(fila));

                    }
                    break;
            case 4: if(!filaVazia(fila))
                    {
                        printf("Item [%d] eh o ultimo da fila\n", ultimo(fila));
                    }
                    break;
            case 5: desenfileirar(&fila);
        }
    }while(opc != 6);
    printf("Fika!!! C eh a melhor linguagem!!!\n");
    return 0;
}