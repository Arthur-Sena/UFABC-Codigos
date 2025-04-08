#include<stdio.h>
#include<stdlib.h>

typedef struct Item {
    int valor;
    struct Item* anterior;
} Item;

typedef struct Pilha {
    Item* ultimo;
    int topo;
} Pilha;

void empilhar(Pilha* p, int valor)
{
    Item* i = (Item*) malloc (sizeof(Item));
    i->valor = valor;
    i->anterior = p->ultimo != NULL ? p->ultimo : NULL;

    p->ultimo = i;
    p->topo = p->topo + 1;
}

void desempilhar(Pilha* p)
{
    if (p == NULL || p->topo == -1)
        return;

    printf("[%d]\n", p->ultimo->valor);
    p->ultimo = p->ultimo->anterior;
    p->topo -= 1;
}

void mostrar(Pilha* p)
{
    if (p == NULL || p->topo == -1)
        return;
    
    Item* i = p->ultimo;
    for (int j = p->topo; j > 0; j--)
    {
        printf("%d ", i->valor);
        i = i->anterior;
    }
    printf("%d\n", i->valor);
}

int main(){
    char opc;
    int valor;

    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->ultimo = NULL;
    p->topo = -1;
    while (scanf("%c", &opc) != EOF)
    {
        if (opc == 'E')
            scanf("%d", &valor);
    
        switch (opc)
        {
            case 'E':
                empilhar(p, valor);
                break;
            case 'D':
                desempilhar(p);
                break;
            case 'M':
                mostrar(p);
                break;
        }
    }

    return 0;
}