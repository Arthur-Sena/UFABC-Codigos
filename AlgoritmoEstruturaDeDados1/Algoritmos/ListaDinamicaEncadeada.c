#include<stdio.h>
#include<stdlib.h>

struct tItem
{
    int chave;
    struct tItem *proximo;
};

struct tLista
{
    struct tItem *primeiro;
};

struct tLista * criarLista();
struct tItem * criarItem(int);
int listaVazia(struct tLista *);
struct tItem * primeiro(struct tLista *);
void mostrarLista(struct tLista *);
struct tItem * buscar(struct tLista *, int);
void inserir(struct tLista *, struct tItem *);
struct tItem * remover(struct tLista *, int);

int main()
{
    int opc, chave;
    struct tItem *it;
    struct tLista *lista = criarLista();

    do
    {
        do
        {
            printf("Escolha uma das opcoes a seguir:\n");
            printf("1 - Inserir na Lista\n");
            printf("2 - Mostrar Lista\n");
            printf("3 - Buscar na Lista\n");
            printf("4 - Remover da Lista\n");
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
            case 1: inserir(lista, criarItem(chave));
                    break;
            case 2: mostrarLista(lista);
                    break;
            case 3: printf("O item [%d] %slocalizado na lista\n", chave, (buscar(lista, chave)!=NULL?"":"NAO "));
                    break;
            case 4: it = remover(lista, chave);
                    if(it != NULL)
                    {
                        printf("O item [%d] foi removido da lista\n", it->chave);
                        free(it);
                    }
                    break;
        }
    }while(opc != 5);
    printf("........\n");
    return 0;
}

struct tLista * criarLista()
{
    struct tLista *l = (struct tLista*) malloc(sizeof(struct tLista));
    if(l != NULL)
    {
        l->primeiro = NULL;
    }
    return l;
}

struct tItem * criarItem(int chave)
{
    struct tItem *it = (struct tItem*) malloc(sizeof(struct tItem));
    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

int listaVazia(struct tLista *l)
{
    return l->primeiro == NULL;
}

struct tItem * primeiro(struct tLista *l)
{
    return l->primeiro;
}

void mostrarLista(struct tLista *l)
{
    struct tItem *it = primeiro(l);
    while(it != NULL)
    {
        printf("%d%s", it->chave, it->proximo != NULL?" ":"\n");
        it = it->proximo;
    }
}

struct tItem * buscar(struct tLista *l, int chave)
{
    struct tItem *it = primeiro(l);
    while(it != NULL && it->chave < chave)
    {
        it = it->proximo;
    }

    if(it != NULL && it->chave == chave)
    {
        return it;
    }
    else
    {
        return NULL;
    }
}

void inserir(struct tLista *l, struct tItem *novo)
{
    struct tItem *anterior = NULL, *atual = primeiro(l);
    while(atual != NULL && atual->chave < novo->chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    novo->proximo = atual;
    if(anterior != NULL) // inserindo no meio ou final
    {
        anterior->proximo = novo;
    }
    else // inserindo no inicio
    {
        l->primeiro = novo;
    }
}

struct tItem * remover(struct tLista *l, int chave)
{
    struct tItem *anterior = NULL, *rem = primeiro(l);
    while(rem != NULL && rem->chave < chave)
    {
        anterior = rem;
        rem = rem->proximo;
    }

    if(rem != NULL && rem->chave == chave)
    {
        if(anterior != NULL)
        {
            anterior->proximo = rem->proximo;
        }
        else
        {
            l->primeiro = rem->proximo;
        }
        return rem;
    }
    else
    {
        return NULL;
    }
}