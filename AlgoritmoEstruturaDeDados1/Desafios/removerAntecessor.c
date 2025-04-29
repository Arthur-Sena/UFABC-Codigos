#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region "Types"
typedef struct No 
{
    int chave;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;
} No;

typedef struct Arvore
{
    No *raiz;
} Arvore;
#pragma endregion

#pragma region "Interface"
void inserir(Arvore *, No *);
No * remover(Arvore *, int);
void preOrder(No *);
void removerAntecessor(No *);
No * antecessor(No *);
#pragma endregion

#pragma region "Criar Nó/Arvore"
No *criarNo(char n)
{
    No* it = (No*)malloc(sizeof(No));
    if(it == NULL) return NULL;
    
    it->chave = n;
    it->pai = NULL;
    it->esquerda = NULL;
    it->direita = NULL;

    return it;
}

Arvore *criarArvore()
{
    Arvore *a = (Arvore*)malloc(sizeof(Arvore));
    if(a != NULL)
        a->raiz = NULL;

    return a;
}
#pragma endregion

No *raiz(Arvore *a)
{
    return a->raiz;
}

int arvoreVazia(Arvore *a)
{
    return raiz(a) == NULL;
}

int main()
{
    Arvore *a = criarArvore();

    int qntNo;
    scanf("%d", &qntNo);

    int valorAtual;
    for (int i = 0; i < qntNo; i++)
    {
        scanf("%d", &valorAtual);
        No *novo = criarNo(valorAtual);
        inserir(a, novo);
    }

    int qntRemocao;
    scanf("%d", &qntRemocao);
    for (int j = 0; j < qntRemocao; j++)
    {
        scanf("%d", &valorAtual);
        remover(a, valorAtual);
    }
    preOrder(a->raiz);
    return 0;
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

void inserir(Arvore *a, No *novo)
{
    No *pai = NULL, *filho = raiz(a);

    while(filho != NULL)
    {
        pai = filho;
        if(filho->chave == novo->chave)
            return;
        else if(filho->chave > novo->chave)
            filho = filho->esquerda;
        else
            filho = filho->direita;
    }
    
    if(pai != NULL)
    {
        novo->pai = pai;
        if(pai->chave >= novo->chave)
            pai->esquerda = novo;
        else
            pai->direita = novo;
    }
    else
        a->raiz = novo;
}

No *remover(Arvore *a, int rem)
{
    No *pai = NULL, *filho = raiz(a);

    while(filho != NULL && filho->chave != rem)//Buscando valor pra remover
    {
        pai = filho;
        if(filho->chave >= rem)
            filho = filho->esquerda;
        else
            filho = filho->direita;
    }

    if(filho != NULL) // Encontrei o valor a ser removido
    {
        if(filho->direita == NULL && filho->esquerda == NULL) // Removendo uma folha
        {
            if(pai != NULL) // Não é uma raíz
            {
                if(pai->direita == filho)
                    pai->direita = NULL;
                else
                    pai->esquerda = NULL;
            }
            else // É uma raíz
                a->raiz = NULL;
        }
        else if(filho->direita != NULL && filho->esquerda != NULL) // Removendo um pai de dois filhos
        {
            No* ant = antecessor(filho);
            if(ant != NULL)
            {
                int chaveOriginal = filho->chave;
                filho->chave = ant->chave;
                removerAntecessor(ant);
                ant->chave = chaveOriginal;
                return ant;
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

No *antecessor(No *n)
{
    if(n != NULL)
    {
        No *ant = n->esquerda;
        while(ant->direita != NULL)
            ant = ant->direita;

        return ant;
    }
}

void removerAntecessor(No *ant)
{
    if(ant != NULL)
    {
        No *pai = ant->pai;
        if(pai != NULL)
        {
            if(pai->direita == ant)
                pai->direita = ant->esquerda;
            else
                pai->esquerda = ant->esquerda;
        }

        if(ant->esquerda != NULL)
            ant->esquerda->pai = pai;
        
        ant->pai = NULL;
        ant->esquerda = NULL;
        ant->direita = NULL;
    }
}