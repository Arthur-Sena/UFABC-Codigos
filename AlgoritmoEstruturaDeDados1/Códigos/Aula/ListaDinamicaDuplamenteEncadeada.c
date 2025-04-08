#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    int chave;
    struct tItem *proximo;
    struct tItem *anterior;
};

struct tLista
{
    struct tItem *primeiro;
    struct tItem *ultimo;
};

struct tItem * criarItem(int);
struct tLista * criarLista();
struct tItem * primeiro(struct tLista *);
struct tItem * ultimo(struct tLista *);
int listaVazia(struct tLista *);
struct tItem * buscar(struct tLista *, int);
void mostrarListaPrimeiroUltimo(struct tLista *);
void mostrarListaUltimoPrimeiro(struct tLista *);
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
            printf("2 - Mostrar Lista (Primeiro-Ultimo)\n");
            printf("3 - Mostrar Lista (Ultimo-Primeiro)\n");
            printf("4 - Primeiro da Lista\n");
            printf("5 - Ultimo da Lista\n");
            printf("6 - Buscar na Lista\n");
            printf("7 - Remover da Lista\n");
            printf("8 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        }while(opc < 1 || opc > 8);

        if(opc == 1 || opc == 6 || opc == 7)
        {
            printf("Informe o valor da chave: ");
            scanf("%d", &chave);
        }
        switch(opc)
        {
            case 1: inserir(lista, criarItem(chave));
                    break;
            case 2: mostrarListaPrimeiroUltimo(lista);
                    break;
            case 3: mostrarListaUltimoPrimeiro(lista);
                    break;
            case 4: if(!listaVazia(lista))
                    {
                        printf("Primeiro item da lista: %d\n", primeiro(lista)->chave);
                    }
                    break;
            case 5: if(!listaVazia(lista))
                    {
                        printf("Ultimo item da lista: %d\n", ultimo(lista)->chave);
                    }
                    break;
            case 6: printf("Item %d%slocalizado na lista!\n", chave, buscar(lista, chave) != NULL?" ":" NAO ");
                    break;
            case 7: it = remover(lista, chave);
                    if(it != NULL)
                    {
                        printf("Item chave %d removido da lista!\n", it->chave);
                        free(it);
                    }
        }
    }while(opc != 8);
    printf(" . . . . . . . . .\n");
    return 0;
}

struct tItem * criarItem(int chave)
{
    struct tItem *it = (struct tItem *) malloc(sizeof(struct tItem));
    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
        it->anterior = NULL;
    }
    return it;
}

struct tLista * criarLista()
{
    struct tLista *l = (struct tLista *) malloc(sizeof(struct tLista));
    if(l != NULL)
    {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

struct tItem * primeiro(struct tLista *l)
{
    return l->primeiro;
}

struct tItem * ultimo(struct tLista *l)
{
    return l->ultimo;
}

int listaVazia(struct tLista *l)
{
    return primeiro(l) == NULL && ultimo(l) == NULL;
}

struct tItem * buscar(struct tLista *l, int chave)
{
    struct tItem *atual = primeiro(l);

    while(atual != NULL && atual->chave != chave)
    {
        atual = atual->proximo;
    }
    return atual;
}

void mostrarListaPrimeiroUltimo(struct tLista *l)
{
    struct tItem *atual = primeiro(l);

    while(atual != NULL)
    {
        printf("%d%s", atual->chave, atual->proximo != NULL?" ":"\n");
        atual = atual->proximo;
    }
}

void mostrarListaUltimoPrimeiro(struct tLista *l)
{
    struct tItem *atual = ultimo(l);

    while(atual != NULL)
    {
        printf("%d%s", atual->chave, atual->anterior != NULL?" ":"\n");
        atual = atual->anterior;
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
    novo->anterior = anterior;
    if(anterior != NULL) // inserindo no meio ou no final
    {
        if(atual != NULL) // no meio
        {
            atual->anterior = novo;
        }
        else // no final
        {
            l->ultimo = novo;
        }
        anterior->proximo = novo;
    }
    else // inserindo no inicio
    {
        if(!listaVazia(l)) // no inicio de uma lista com elementos
        {
            atual->anterior = novo;
        }
        else // no inicio de uma lista vazia, ou seja, o primeiro
        {
            l->ultimo = novo;
        }
        l->primeiro = novo;
    }
}

struct tItem * remover(struct tLista *l, int chave)
{
    struct tItem * anterior = NULL, *atual = primeiro(l);

    while(atual != NULL && atual->chave != chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual != NULL)
    {
        if(anterior != NULL) // removendo do meio ou do final
        {
            anterior->proximo = atual->proximo;
        }
        else // removendo do inicio
        {
            l->primeiro = atual->proximo;
        }
        if(atual != ultimo(l)) // removendo do meio OU removendo o primeiro de uma lista com mais elementos
        {
            atual->proximo->anterior = anterior; // (*(*atual).proximo).anterior
        }
        else // removendo do final OU removendo o primeiro de uma lista com um UNICO elemento.
        {
            l->ultimo = anterior;
        }
        atual->proximo = NULL;
        atual->anterior = NULL;
    }
    return atual;
}