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
No * criarNo(int);
Arvore * criarArvore();
No * raiz(Arvore *);
int arvoreVazia(Arvore *);

No * buscar(Arvore *, int);

void inserir(Arvore *, No *);

No * antecessor(No *);
void removerAntecessor(No *);
No * remover(Arvore *, int);

void preOrder(No *);
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

    scanf("%d", &qnt_remove);
    for (int j = 0; j < qnt_remove; j++)
    {
        int remove_value;
        scanf("%d", &remove_value);
        remover(a, remove_value);
    }

    preOrder(raiz(a));
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

#pragma region "Raiz - Verificar Se Vazia"
No *raiz(Arvore *a)
{
    return a->raiz;
}

int arvoreVazia(Arvore *a)
{
    return raiz(a) == NULL;
}
#pragma endregion

#pragma region "Antecessor"
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
#pragma endregion

#pragma region  "Inserir/Remover"
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