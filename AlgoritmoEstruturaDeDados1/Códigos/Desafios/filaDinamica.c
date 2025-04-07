#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    int valor;
    struct tItem *proximo;
};

struct tFila
{
    struct tItem *primeiro;
};

struct tFila *criarFila();
void incluirElemento(struct tFila *f, int valor);
struct tItem* topo(struct tFila *f);
void exibirFila(struct tFila *f);

void excluirElemento(struct tFila *f);

int main()
{
    struct tFila *fila = criarFila();
    char opc;
    int valor;

    do
    {
        // do
        // {
        //     printf("Escolha uma das opcoes a seguir:\n");
        //     printf("E - Inserir\n");
        //     printf("D - Excluir\n");
        //     printf("M - Exibir\n");
        //     printf("S - Sair\n");
        //     printf("==> ");
        //     scanf("%c", &opc);
        // } while (opc != 'E' && opc != 'D' && opc != 'M' && opc != 'S');

        switch (opc)
        {
            case 'E': 
                scanf("%d", &valor);
                incluirElemento(fila, valor);
                break;
            case 'M':
                exibirFila(fila);
                break;
            case 'D':
                excluirElemento(fila);
            default:
                break;
        }
    } while (scanf("%c", &opc) != EOF);
    return 0;
}

struct tFila* criarFila()
{
    struct tFila *f = (struct tFila *)malloc(sizeof(struct tFila *));
    if (f == NULL)
        return NULL;

    f->primeiro = NULL;
    return f;
}

struct tItem* topo(struct tFila *f)
{
    if (f == NULL)
        return NULL; // Fila vazia

    struct tItem* atual = f->primeiro;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    return atual;
}

void incluirElemento(struct tFila* f, int valor)
{
    if (f == NULL)
        return; 
    
    struct tItem* item = (struct tItem*) malloc (sizeof(struct tItem));
    if (item == NULL)
        return;
    
    item->valor = valor;
    item->proximo = NULL; 

    if (f->primeiro == NULL)
        f->primeiro = item;
    else
    {
        struct tItem* t = topo(f);
        t->proximo = item;
    } 
}

void exibirFila(struct tFila* f)
{
    struct tItem* item = f->primeiro;
    while (item->proximo != NULL)
    {
        printf("%d ", item->valor);
        item = item->proximo;
    }
    printf("%d\n", item->valor);
}

void excluirElemento(struct tFila* f)
{
    if (f->primeiro == NULL)
        return;
    
    struct tItem* primeiro = f->primeiro;
    if (primeiro->proximo == NULL)
        f->primeiro = NULL;
    else
        f->primeiro = primeiro->proximo;
    printf("<%d>\n", primeiro->valor);
    free(primeiro);
}