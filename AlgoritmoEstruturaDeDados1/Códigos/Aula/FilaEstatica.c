#include<stdio.h>
#include<stdlib.h>

struct tFila
{
    int *itens;
    int tamanho;
    int inicio;
    int final;
};

struct tFila criarFila(int n)
{
    struct tFila f;
    f.itens = (int *) malloc(n * sizeof(int));
    f.tamanho = n;
    f.inicio = -1;
    f.final = -1;

    return f;
}

int filaVazia(struct tFila f)
{
    return f.inicio == -1 && f.final == -1 || f.inicio > f.final;
}

int filaCheia(struct tFila f)
{
    return f.final == f.tamanho-1;
}

int primeiro(struct tFila f)
{
    return f.itens[f.inicio];
}

int ultimo(struct tFila f)
{
    return f.itens[f.final];
}

void mostrarFila(struct tFila f)
{
    int i;
    if(!filaVazia(f))
    {
        for(i = f.inicio; i <= f.final; i++)
        {
            if(i!=f.final)
            {
                printf("%d ", f.itens[i]);
            }
            else
            {
                printf("%d\n", f.itens[i]);
            }
            //printf("%d%s", f.itens[i], i!=f.final?" ":"\n");
        }
    }
}

void enfileirar(struct tFila *f, int novo)
{
    if(!filaCheia(*f))
    {
        if(f->inicio == -1)
        {
            f->inicio = f->inicio + 1;
        }
        f->final = f->final + 1;
        f->itens[f->final] = novo;
    }
}

void desenfileirar(struct tFila *f)
{
    if(!filaVazia(*f))
    {
        f->inicio = f->inicio + 1;
    }
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