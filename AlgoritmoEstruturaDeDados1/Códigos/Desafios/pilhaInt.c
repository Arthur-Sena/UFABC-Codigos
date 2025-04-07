#include<stdio.h>
#include<stdlib.h>

struct tPilha
{
    int *itens;
    int tamanho;
    int topo;
};

struct tPilha criarPilha(int n)
{
    struct tPilha p;
    p.itens = (int*) malloc(n * sizeof(int));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

void empilhar(struct tPilha*, int);
void desempilhar(struct tPilha*);
void topoParaBase(struct tPilha*);
void baseParaTopo(struct tPilha*);
void topo(struct tPilha*);

int main()
{
    int n, valor;
    char opc;
    scanf("%d", &n);

    struct tPilha pilha = criarPilha(n);
    while (scanf("%c", &opc) != EOF)
    {
        if (opc == 'E')
            scanf("%d", &valor);
        
        switch(opc)
        {
            case 'E': 
                empilhar(&pilha, valor);
                break;
            case 'D':
                desempilhar(&pilha);
                break;
            case 'T':
                topo(&pilha);
                break;
            case 'X':
                topoParaBase(&pilha);
                break;
            case 'B':
                baseParaTopo(&pilha);
                break;
        }
    }
    return 0;
}

void empilhar(struct tPilha* p, int valor)
{
    if (p->topo == p->tamanho-1)
        return;
    p->topo = p->topo + 1;
    p->itens[p->topo] = valor;
}

void desempilhar(struct tPilha * p)
{
    if (p->topo == -1)
        return;
    p->topo -= 1;
}

void topoParaBase(struct tPilha* p)
{
    if (p->topo == -1)
        return;

    for (int i = p->topo; i > 0; i--)
        printf("%d ", p->itens[i]);
    printf("%d\n", p->itens[0]);
}

void baseParaTopo(struct tPilha* p)
{
    if (p->topo == -1)
        return;

    for (int i = 0; i < p->topo; i++)
        printf("%d ", p->itens[i]);
    printf("%d\n", p->itens[p->topo]);
}

void topo(struct tPilha* p)
{
    if (p->topo == -1)
        return;
    
    printf("%d\n", p->itens[p->topo]);
}
