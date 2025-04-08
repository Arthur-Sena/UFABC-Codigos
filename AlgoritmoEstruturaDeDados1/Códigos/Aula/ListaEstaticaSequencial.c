#include<stdio.h>
#include<stdlib.h>

struct tLista
{
    int *itens;
    int tamanho;
    int quantidade;
};

struct tLista criarLista(int n)
{
    struct tLista l;
    l.itens = (int*) malloc(n * sizeof(int));
    l.tamanho = n;
    l.quantidade = 0;
    return l;
}

int listaCheia(struct tLista l)
{
    return l.quantidade == l.tamanho;
}

int listaVazia(struct tLista l)
{
    return l.quantidade == 0;
}

void mostrarLista(struct tLista l)
{
    int i;
    for(i=0; i<l.quantidade; i++)
    {
        printf("%d%s", l.itens[i], i<l.quantidade-1?" ":"\n");
    }
}

int buscaLista(struct tLista l, int chave)
{
    int i;
    for(i=0; i<l.quantidade; i++)
    {
        if(l.itens[i] == chave)
        {
            return i;
        }
    }
    return -1;
}

void inserir(struct tLista *l, int chave)
{
    int i, j;
    if(!listaCheia(*l))
    {
        for(i=0; l->itens[i] < chave && i < l->quantidade; i++);
        for(j=l->quantidade-1; j>=i; j--)
        {
            l->itens[j+1] = l->itens[j];
        }
        l->itens[i] = chave;
        l->quantidade += 1;
    }
}

void remover(struct tLista *l, int iRem)
{
    int i;
    if(!listaVazia(*l) && iRem != -1)
    {
        for(i=iRem; i<l->quantidade-1; i++)
        {
            l->itens[i] = l->itens[i+1];
        }
        l->quantidade -= 1;
    }
}

int main()
{
    int opc, n, chave, iChave;
    struct tLista lista;

    printf("Informe o tamanho da lista, por favor: ");
    scanf("%d", &n);
    lista = criarLista(n);
    do
    {
        do
        {
            printf("Escolha uma das opcoes a seguir:\n");
            printf("1 - Inserir\n");
            printf("2 - Mostrar Lista\n");
            printf("3 - Buscar Lista\n");
            printf("4 - Remover\n");
            printf("5 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        }while(opc < 1 || opc > 5);

        if(opc == 1 || opc == 3 || opc == 4)
        {
            printf("Informe o valor da chave: ");
            scanf("%d", &chave);
        }
        switch(opc)
        {
            case 1: inserir(&lista, chave);
                    break;
            case 2: mostrarLista(lista);
                    break;
            case 3: iChave = buscaLista(lista, chave);
                    if(iChave != -1)
                    {
                        printf("Item (%d) localizado na Lista\n", lista.itens[iChave]);
                    }
                    else
                    {
                        printf("Item (%d) NAO localizado na Lista\n", chave);
                    }
                    break;
            case 4: remover(&lista, buscaLista(lista, chave));
        }
    }while(opc != 5);
    printf("Fika! Bjo! Entaum tchau!\n");
    return 0;
}