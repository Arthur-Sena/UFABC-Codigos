#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tNo 
{
    int chave;
    struct tNo *esquerda;
    struct tNo *direita;
    struct tNo *pai;
} No;

typedef struct tArvore
{
    No *raiz;
} Arvore;


No * criarNo(int);
No * raiz(Arvore *);
Arvore * criarArvore();
int arvoreVazia(Arvore *);
No * buscar(Arvore *, int);
void inserir(Arvore *, No *);
No * antecessor(No *);
No * sucessor(No *);

int main()
{
    char opt[25];
    int chave;
    No *novo, *busca, *resp;
    Arvore *a = criarArvore();

    while(scanf("%s", opt) != EOF)
    {
        if(strcmp(opt, "insert") == 0)
        {
            scanf("%d", &chave);
            novo = criarNo(chave);
            inserir(a, novo);
        }
        else if(strcmp(opt, "immediately-greater") == 0)
        {
            scanf("%d", &chave);
            busca = buscar(a, chave);
            
            if(busca != NULL)
            {
                resp = sucessor(busca);
                if(resp != NULL)
                    printf("%d\n", resp->chave);
                else
                    printf("nao ha imediatamente maior que %d\n", busca->chave);
            }
        }
        else if(strcmp(opt, "immediately-less") == 0)
        {
            scanf("%d", &chave);
            busca = buscar(a, chave);

            if(busca != NULL)
            {
                resp = antecessor(busca);
                if(resp != NULL)
                    printf("%d\n", resp->chave);
                else
                    printf("nao ha imediatamente menor que %d\n", busca->chave);
            }
        }
    }
    return 0;
}

No *criarNo(int n)
{
    No* it = (No*)malloc(sizeof(No));
    if(it != NULL)
    {
        it->chave = n;
        it->pai = NULL;
        it->esquerda = NULL;
        it->direita = NULL;
    }

    return it;
}

Arvore *criarArvore()
{
    Arvore *a = (Arvore*)malloc(sizeof(Arvore));
    if(a != NULL)
        a->raiz = NULL;
    
    return a;
}


No *raiz(Arvore *a)
{
    return a->raiz;
}

int arvoreVazia(Arvore *a)
{
    return raiz(a) == NULL;
}

No *buscar(Arvore *a, int chave)
{
    No *no = raiz(a);

    while(no != NULL && no->chave != chave)
    {
        if(no->chave < chave)
            no = no->direita;
        else
            no = no->esquerda;
    }
    return no;
}

void inserir(Arvore *a, No *novo)
{
    
    No *pai = NULL, *busca = NULL, *filho = raiz(a);

    busca = buscar(a, novo->chave);

    if(busca == NULL)
    {
        while(filho != NULL)
        {
            pai = filho;
            if(filho->chave < novo->chave)
                filho = filho->direita;
            else
                filho = filho->esquerda;
        }

        if(pai != NULL)
        {
            novo->pai = pai;
            if(pai->chave < novo->chave)
                pai->direita = novo;
            else
                pai->esquerda = novo;
        }
        else
            a->raiz = novo;
    }
}

No *antecessor(No *n)
{
    if(n == NULL || n->esquerda == NULL)
        return NULL;

    No *ant = n->esquerda;

    while(ant->direita != NULL)
    {
        ant = ant->direita;
    }

    return ant;
}

No *sucessor(No *n)
{
    if(n == NULL || n->direita == NULL)
        return NULL;

    No *suc = n->direita;

    while(suc->esquerda != NULL)
    {
        suc = suc->esquerda;
    }

    return suc;
}