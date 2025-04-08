#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    int chave;
    struct tItem *anterior;
};

struct tPilha
{
    struct tItem *topo;
};

struct tItem * criarItem(int chave)
{
    struct tItem *it = (struct tItem *) malloc(sizeof(struct tItem));
    if(it != NULL)
    {
        it->chave = chave;
        it->anterior = NULL;
    }
    return it;
}

struct tPilha * criarPilha()
{
    struct tPilha *p = (struct tPilha *) malloc(sizeof(struct tPilha));
    if(p != NULL)
    {
        p->topo = NULL;
    }
    return p;
}

int pilhaVazia(struct tPilha *p)
{
    return p->topo == NULL;
}

struct tItem *topo(struct tPilha *p)
{
    return p->topo;
}

void mostrarPilhaTopoBase(struct tPilha *p)
{
    struct tItem *it = topo(p);
    while(it != NULL)
    {
        printf("%d%s", it->chave, it->anterior != NULL?" ":"\n");
        it = it->anterior;
    }
}

void empilhar(struct tPilha *p, struct tItem *novo)
{
    novo->anterior = p->topo;
    p->topo = novo;
}

struct tItem * desempilhar(struct tPilha *p)
{
    struct tItem *it = topo(p);
    if(!pilhaVazia(p))
    {
        p->topo = it->anterior;
        it->anterior = NULL;
    }
    return it;
}

int main()
{
    int opc, chave;
    struct tItem *it;
    struct tPilha *pilha = criarPilha();

    do
    {
        do
        {
            printf("Escolha uma das opcoes a seguir:\n");
            printf("1 - Empilhar\n");
            printf("2 - Mostrar Pilha (Topo-Base)\n");
            printf("3 - Topo da Pilha\n");
            printf("4 - Desempilhar\n");
            printf("5 - Mostrar Pilha (Base-Topo)\n");
            printf("6 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        }while(opc < 1 || opc > 6);

        switch(opc)
        {
            case 1: printf("Informe o valor da chave: ");
                    scanf("%d", &chave);
                    empilhar(pilha, criarItem(chave));
                    break;
            case 2: mostrarPilhaTopoBase(pilha);
                    break;
            case 3: if(!pilhaVazia(pilha))
                    {
                        printf("Topo da pilha: <%d>\n", topo(pilha)->chave);
                    }
                    break;
            case 4: it = desempilhar(pilha);
                    if(it != NULL)
                    {
                        printf("Item desempilhado: (%d)\n", it->chave);
                        free(it);
                    }
                    break;
            case 5: printf("Em construcao!!! Homework!\n");
        }
    }while(opc != 6);
    printf("BRASILLLLL!!!!\n");
    return 0;
}