#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tItem
{
    char nome[50];
};

struct tPilha
{
    struct tItem *itens;
    int tamanho;
    int topo;
};

struct tItem criarItem(char *);
struct tPilha criarPilha(int);
struct tItem topo(struct tPilha);
void mostrarPilhaBaseTopo(struct tPilha);
void mostrarPilhaTopoBase(struct tPilha);
int pilhaVazia(struct tPilha);
int pilhaCheia(struct tPilha);
void empilhar(struct tPilha *, struct tItem);
void desempilhar(struct tPilha *);

int main()
{
    int opc, n;
    char nome[50];
    struct tPilha pilha;

    printf("Informe o tamanho da pilha: ");
    scanf("%d", &n);
    pilha = criarPilha(n);

    do
    {
        do
        {
            printf("Escolha uma das opcoes a seguir:\n");
            printf("1 - Empilhar\n");
            printf("2 - Mostrar Pilha Base Topo\n");
            printf("3 - Mostrar Pilha Topo Base\n");
            printf("4 - Topo\n");
            printf("5 - Desempilhar\n");
            printf("6 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        }while(opc < 1 || opc > 6);

        switch(opc)
        {
            case 1: printf("Informe o nome: ");
                    scanf("%s", nome);
                    empilhar(&pilha, criarItem(nome));
                    break;
            case 2: mostrarPilhaBaseTopo(pilha);
                    break;
            case 3: mostrarPilhaTopoBase(pilha);
                    break;
            case 4: if(!pilhaVazia(pilha))
                    {
                        printf("Item [%s] estah no topo da pilha\n", topo(pilha).nome);
                    }
                    break;
            case 5: if(!pilhaVazia(pilha))
                    {
                        printf("Item [%s] desempilhado com sucesso!\n", topo(pilha).nome);
                        desempilhar(&pilha);
                    }
        }
    }while(opc != 6);
    printf("SOME!!!!\n");
    return 0;
}

struct tItem criarItem(char *nome)
{
    struct tItem it;
    strcpy(it.nome, nome);
    return it;
}

struct tPilha criarPilha(int n)
{
    struct tPilha p;
    p.itens = (struct tItem *) malloc(n * sizeof(struct tItem));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

struct tItem topo(struct tPilha p)
{
    return p.itens[p.topo];
}

void mostrarPilhaBaseTopo(struct tPilha p)
{
    int i;
    for(i=0; i<=p.topo; i++)
    {
        printf("%s\n", p.itens[i].nome);
    }
}

void mostrarPilhaTopoBase(struct tPilha p)
{
    if(!pilhaVazia(p))
    {
        printf("%s\n", topo(p).nome);
        desempilhar(&p);
        mostrarPilhaTopoBase(p);
    }
}

int pilhaVazia(struct tPilha p)
{
    return p.topo == -1;
}

int pilhaCheia(struct tPilha p)
{
    return p.topo == p.tamanho-1;
}

void empilhar(struct tPilha *p, struct tItem novo)
{
    if(!pilhaCheia(*p))
    {
        p->itens[++p->topo] = novo;
    }
}

void desempilhar(struct tPilha *p)
{
    if(!pilhaVazia(*p))
    {
        p->topo -= 1;
    }
}