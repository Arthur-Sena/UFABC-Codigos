#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ItemPilha
{
    int valor;
    struct ItemPilha *anterior;
} ItemPilha;

typedef struct Pilha
{
    ItemPilha *topo;
} Pilha;

typedef struct ItemFila
{
    int valor;
    struct ItemFila *proximo;
} ItemFila;

typedef struct Fila
{
    ItemFila *primeiro;
    ItemFila *ultimo;
} Fila;

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha *));
    p->topo = NULL;
}

Fila *criarFila()
{
    Fila *p = (Fila *)malloc(sizeof(Fila *));
    p->primeiro = NULL;
    p->ultimo = NULL;
}

void empilhar(Pilha* p, int valor)
{
    ItemPilha* i = (ItemPilha*) malloc (sizeof(ItemPilha*));
    i->valor = valor;
    i->anterior = p->topo;

    p->topo = i;
}

void exibirPilha(Pilha* p)
{
    ItemPilha* i = p->topo;
    while(i->anterior != NULL)
    {
        printf("%d ", i->valor);
        i = i->anterior;
    }   
    printf("%d\n", i->valor);
}

void desempilhar(Pilha* p)
{
    ItemPilha* i = p->topo;
    p->topo = p->topo->anterior;
    free(i);
}

void pilhaToFila(Pilha* p, Fila* f)
{
    ItemPilha* itemP = p->topo;

    ItemFila* itemF = (ItemFila*) malloc (sizeof(ItemFila));
    itemF->proximo = NULL;
    itemF->valor = itemP->valor;
    
    f->primeiro = itemF;
    f->ultimo = itemF;

    itemP = itemP->anterior;
    while (itemP->anterior != NULL)
    {
        ItemFila* proximoI = (ItemFila*) malloc (sizeof(ItemFila));
        proximoI->valor = itemP->valor;
        proximoI->proximo = NULL;
        
        itemF->proximo = proximoI;
        itemF = proximoI;
        itemP = itemP->anterior; 
        f->ultimo = proximoI;
    }

    ItemFila* proximoI = (ItemFila*) malloc (sizeof(ItemFila));
    proximoI->valor = itemP->valor;
    proximoI->proximo = NULL;
    
    itemF->proximo = proximoI;
    itemF = proximoI;
    itemP = itemP->anterior; 
    f->ultimo = proximoI;
}

void exibirFila(Fila* f)
{
    ItemFila* i = f->primeiro;
    while(i->proximo != NULL)
    {
        printf("%d\n", i->valor);
        i = i->proximo;
    }   
    printf("%d\n", i->valor);
}

int main()
{
    Pilha *p = criarPilha();
    Fila *f = criarFila();
    char opc;
    int valor;
    while (scanf("%c", &opc) != EOF)
    {
        if (opc == 'E')
            scanf("%d", &valor);

        switch (opc)
        {
            case 'E':
                empilhar(p, valor);
                break;
            case 'L':
                exibirPilha(p);
                break;
            case 'D':
                desempilhar(p);
                break;
            case 'F':
                pilhaToFila(p, f);
                break;
            case 'M':
                exibirFila(f);
                break;
        }
    }

    return 0;
}