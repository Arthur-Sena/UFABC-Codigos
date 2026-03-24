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
Arvore * criarArvore();
No * criarNo(int);
No * buscar(Arvore *, int);
No * raiz(Arvore *);
void inserir(Arvore *, No *);
int altura(No* raiz);
#pragma endregion

int main()
{
    Arvore *a = criarArvore();
    
    int qnt_insert, qnt_remove;
    scanf("%d", &qnt_insert);

    for (int i = 0; i < qnt_insert; i++)
    {
        int new_value;
        scanf("%d", &new_value);

        if (buscar(a, new_value) != NULL)
            continue;
        
        No* new_node = criarNo(new_value);
        inserir(a, new_node);
    }

    int altura_arvore = altura(a->raiz);
    printf("%d\n", altura_arvore);

    return 0;
}

No *raiz(Arvore *a)
{
    return a->raiz;
}

int altura(No* raiz){
    if(raiz == NULL)
        return -1;
    
    int alturaesquerda = altura(raiz->esquerda);
    int alturadireita = altura(raiz->direita);

    if(alturaesquerda >= alturadireita)
        return  1 + alturaesquerda;
    return 1 + alturadireita;
}

#pragma region "Criar Nó/Arvore"
No *criarNo(int n)
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

#pragma region  "Inserir"
//Nâo insere valor igual
void inserir(Arvore *a, No *novo)
{
    No *pai = NULL, *filho = raiz(a);

    while(filho != NULL)
    {
        pai = filho;
        if(filho->chave > novo->chave)
            filho = filho->esquerda;
        else
            filho = filho->direita;
    }
    
    if(pai != NULL)
    {
        novo->pai = pai;
        if(pai->chave > novo->chave)
            pai->esquerda = novo;
        else
            pai->direita = novo;
    }
    else
        a->raiz = novo;
    
}
#pragma endregion

#pragma region "Buscar"
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
#pragma endregion