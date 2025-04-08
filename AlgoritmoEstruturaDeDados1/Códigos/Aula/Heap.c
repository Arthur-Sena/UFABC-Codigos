#include<stdio.h>
#include<stdlib.h>

struct tHeap
{
    int *itens;
    int tamanho;
    int quantidade;
};

struct tHeap criarHeap(int n)
{
    struct tHeap h;
    h.itens = (int*) malloc(n * sizeof(int));
    h.tamanho = n;
    h.quantidade = 0;
    return h;
}

int filhoEsquerda(int p)
{
    return (2 * p) + 1;
}

int filhoDireita(int p)
{
    return (2 * p) + 2;
}

int pai(int f)
{
    return (f - 1) / 2;
}

int ultimoPai(int n)
{
    return (n / 2) - 1;
}

void peneirar(struct tHeap *h, int p)
{
    int maior = p, aux;
    if(filhoEsquerda(p) < h->quantidade && h->itens[filhoEsquerda(p)] > h->itens[maior])
    {
        maior = filhoEsquerda(p);
    }
    if(filhoDireita(p) < h->quantidade && h->itens[filhoDireita(p)] > h->itens[maior])
    {
        maior = filhoDireita(p);
    }
    if(maior != p)
    {
        aux = h->itens[maior];
        h->itens[maior] = h->itens[p];
        h->itens[p] = aux;
        peneirar(h, maior);
    }
}

void construirHeap(struct tHeap *h)
{
    int i;
    for(i = ultimoPai(h->quantidade); i>=0; i--)
    {
        peneirar(h, i);
    }
}

void removerMax(struct tHeap *h)
{
    int rem;
    if(h->quantidade > 0)
    {
        rem = h->itens[0];
        h->itens[0] = h->itens[h->quantidade-1];
        h->itens[h->quantidade-1] = rem;
        h->quantidade -= 1;
        peneirar(h, 0);
    }
}

void inserirHeap(struct tHeap *h, int chave)
{
    int indNovo = h->quantidade;
    if(h->quantidade < h->tamanho)
    {
        h->itens[indNovo] = chave;
        h->quantidade += 1;
        if(h->itens[indNovo] > h->itens[pai(indNovo)])
        {
            construirHeap(h);
        }
    }
}

void inserirVetor(struct tHeap *h, int chave)
{
    if(h->quantidade < h->tamanho)
    {
        h->itens[h->quantidade++] = chave;
    }
}

void mostrarHeap(struct tHeap h)
{
    int i;
    for(i=0; i<h.quantidade; i++)
    {
        printf("%d%s", h.itens[i], i<h.quantidade-1?" ":"\n");
    }
}

int main()
{
    int opc, chave;
    struct tHeap heap = criarHeap(10);
    do
    {
        do
        {
            printf("Escolha uma opcao:\n");
            printf("1 - Inserir Heap\n");
            printf("2 - Inserir Vetor\n");
            printf("3 - Mostrar Heap\n");
            printf("4 - Construir Heap\n");
            printf("5 - Remove Maximo\n");
            printf("6 - Sair\n");
            printf("==>");
            scanf("%d", &opc);
        }while(opc < 1 || opc > 6);

        switch(opc)
        {
            case 1: printf("Informe a chave: ");
                    scanf("%d", &chave);
                    inserirHeap(&heap, chave);
                    break;
            case 2: printf("Informe a chave: ");
                    scanf("%d", &chave);
                    inserirVetor(&heap, chave);
                    break;
            case 3: mostrarHeap(heap);
                    break;
            case 4: mostrarHeap(heap);
                    construirHeap(&heap);
                    mostrarHeap(heap);
                    break;
            case 5: removerMax(&heap);
                    break;
        }
    }while(opc != 6);
    printf("Poxa! Entaum tah baum! Volta logo, to cum saudades!\n");
    return 0;
}