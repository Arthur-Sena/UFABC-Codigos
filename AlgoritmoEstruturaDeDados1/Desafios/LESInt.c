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
    for(int i = 0; i < l.quantidade; i++)
        printf("%d%s", l.itens[i], i<l.quantidade-1?" ":"\n");
}

int buscaLista(struct tLista l, int chave)
{
    int i;
    for(i=0; i<l.quantidade; i++)
        if(l.itens[i] == chave)
            return i;
    return -1;
}

void inserir(struct tLista *l, int chave)
{
    int i, j;
    if(!listaCheia(*l))
    {
        if (buscaLista(*l, chave) != -1)
            return;

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
        for(i = iRem; i < l->quantidade-1; i++)        
            l->itens[i] = l->itens[i+1];

        l->quantidade -= 1;
    }
}

int main()
{
    int n, chave, iChave;
    char opc;
    scanf("%d", &n);

    struct tLista lista = criarLista(n);
    while (scanf("%c", &opc) != EOF)
    {
        if(opc == 'I' || opc == 'R' || opc == 'B')
            scanf("%d", &chave);
        
        switch(opc)
        {
            case 'I': inserir(&lista, chave);
                    break;
            case 'M': mostrarLista(lista);
                    break;
            case 'B': iChave = buscaLista(lista, chave);
                    if(iChave != -1)
                        printf("SIM\n");
                    else
                        printf("NAO\n");
                    break;
            case 'R': remover(&lista, buscaLista(lista, chave));
        }
    }
    return 0;
}