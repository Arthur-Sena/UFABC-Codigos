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
Arvore * criarArvore();
No * raiz(Arvore *);
int arvoreVazia(Arvore *);
void preOrder(No *);
void inOrder(No *);
void postOrder(No *);
No * buscar(Arvore *, int);
void inserir(Arvore *, No *);
No * remover(Arvore *, int);
No * sucessor(No *);
void removerSucessor(No *);

int main()
{
    char opt[15];
    int chave;
    No *novo, *rem;
    Arvore *a = criarArvore();

    while(scanf("%s", opt) != EOF)
    {
        if(strcmp(opt, "insert") == 0)
        {
            scanf("%d", &chave);
            novo = criarNo(chave);
            inserir(a, novo);
        }
        else if(strcmp(opt, "delete") == 0)
        {
            scanf("%d", &chave);
            rem = remover(a, chave);
            if(rem != NULL)
            {
                printf("%d\n", rem->chave);
            }
        }
        else if(strcmp(opt, "in-order") == 0)
        {
            inOrder(raiz(a));
        }
        else if(strcmp(opt, "post-order") == 0)
        {
            postOrder(raiz(a));
        }
        else if(strcmp(opt, "pre-order") == 0)
        {
            preOrder(raiz(a));
        }
    }
    return 0;
}

void inOrder(No *r)
{
    if(r != NULL)
    {
        inOrder(r->esquerda);
        printf("%d\n", r->chave);
        inOrder(r->direita);
    }
}

void postOrder(No *r)
{
    if(r != NULL)
    {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%d\n", r->chave);
    }
}

void preOrder(No *r)
{
    if(r != NULL)
    {
        printf("%d\n", r->chave);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
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
    {
        a->raiz = NULL;
    }
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
        {
            no = no->direita;
        }
        else
        {
            no = no->esquerda;
        }
    }
    return no;
}

void inserir(Arvore *a, No *novo)
{
    
    No *pai = NULL, *filho = raiz(a);

    while(filho != NULL)
    {
        pai = filho;
        if(filho->chave >= novo->chave)
        {
            filho = filho->esquerda;
        }
        else
        {
            filho = filho->direita;
        }
    }
    
    if(pai != NULL)
    {
        novo->pai = pai;
        if(pai->chave >= novo->chave)
        {
            pai->esquerda = novo;
        }
        else
        {
            pai->direita = novo;
        }
    }
    else
    {
        a->raiz = novo;
    }
    
}

No *remover(Arvore *a, int rem)
{
    No *pai = NULL, *filho = raiz(a);

    while(filho != NULL && filho->chave != rem)
    {
        pai = filho;
        if(filho->chave < rem)
        {  
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) // Encontrei o valor para se remover
    {
        if(filho->direita == NULL && filho->esquerda == NULL) // Removendo uma folha
        {
            if(pai != NULL) // Não é uma raíz
            {
                if(pai->direita == filho)
                {
                    pai->direita = NULL;
                }
                else
                {
                    pai->esquerda = NULL;
                }
            }
            else // É uma raíz
            {
                a->raiz = NULL;
            }
        }

        else if(filho->direita != NULL && filho->esquerda != NULL) // Removendo um pai de dois filhos
        {
            No* suc = sucessor(filho);
            if(suc != NULL)
            {
                int chaveOriginal = filho->chave;
                filho->chave = suc->chave;
                removerSucessor(suc);
                suc->chave = chaveOriginal;
                return suc;
            }
        }

        else // Removendo pai de um filho só
        {
            if(pai != NULL) // Não é raíz
            {
                if(pai->esquerda == filho) // Nó a ser removido é filho esquerdo do seu pai
                {
                    if(filho->esquerda != NULL)
                    {
                        pai->esquerda = filho->esquerda;
                        filho->esquerda->pai = pai;
                    }
                    else
                    {
                        pai->esquerda = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
                else // Nó a ser removido é filho direito de seu pai
                {
                    if(filho->esquerda != NULL)
                    {
                        pai->direita = filho->esquerda;
                        filho->esquerda->pai = pai;
                    }
                    else
                    {
                        pai->direita = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
            }
            else // É raíz
            {
                if(filho->esquerda != NULL)
                {
                    a->raiz = filho->esquerda;
                    filho->esquerda->pai = NULL;
                }
                else
                {
                    a->raiz = filho->direita;
                    filho->direita->pai = NULL;
                }
            }
        }
        filho->pai = NULL;
        filho->esquerda = NULL;
        filho->direita = NULL;
    }
    return filho;
}

No *sucessor(No *n)
{
    if(n != NULL)
    {
        No *suc = n->direita;

        while(suc->esquerda != NULL)
        {
            suc = suc->esquerda;
        }

        return suc;
    }
}

void removerSucessor(No *suc)
{
    if(suc != NULL)
    {
        No *pai = suc->pai;

        if(pai != NULL)
        {
            if(pai->esquerda == suc)
            {
                pai->esquerda = suc->direita;
            }
            else
            {
                pai->direita = suc->direita;
            }
        }

        if(suc->direita != NULL)
        {
            suc->direita->pai = pai;
        }

        suc->pai = NULL;
        suc->esquerda = NULL;
        suc->direita = NULL;
    }
}