#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int numItens, i, chave;
    No *it;
    Arvore *a = criarArvore();
    
    scanf("%d", &numItens);
    for(i=0; i < numItens; i++)
    {
        scanf("%d", &chave);
        it = buscar(a, chave);
        
        if(it == NULL)
        {   
            it = criarNo(chave);
            inserir(a, it);
        }
        else
            printf("Chave %d ja existe na arvore!\n", chave);
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