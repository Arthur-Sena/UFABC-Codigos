#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma region "Types"
typedef struct tNo 
{
    char chave;
    struct tNo *esquerda;
    struct tNo *direita;
    struct tNo *pai;
} No;

typedef struct tArvore
{
    No *raiz;
} Arvore;
#pragma endregion

#pragma region "Interface"
No * criarNo(char);
Arvore * criarArvore();
No * raiz(Arvore *);
int arvoreVazia(Arvore *);

void preOrder(No *);
void inOrder(No *);
void postOrder(No *);

void preOrderInline(No *, int *);
void inOrderInline(No *, int *);
void postOrderInline(No *, int *);

void inserir(Arvore *, No *);
No * remover(Arvore *, char);

No * buscar(Arvore *, char);
No * sucessor(No *);
No * antecessor(No *);
No * maiorElemento(No *raiz);
No * menorElemento(No *raiz);

void removerSucessor(No *);
void removerAntecessor(No *);
#pragma endregion

int main()
{
    char opt[15];
    char chave;
    No *novo, *rem;
    Arvore *a = criarArvore();

    while(scanf("%s", opt) != EOF)
    {
        if(strcmp(opt, "insert") == 0)
        {
            scanf(" %c", &chave);
            novo = criarNo(chave);
            inserir(a, novo);
        }
        else if(strcmp(opt, "delete") == 0)
        {
            scanf(" %c", &chave);
            rem = remover(a, chave);
            if(rem != NULL)
                printf("%c\n", rem->chave);
        }
        // else if(strcmp(opt, "in-order") == 0)
        // {
        //     if(arvoreVazia(a)) continue;

        //     int primeiro = 1;
        //     inOrderInline(raiz(a), &primeiro);
        //     printf("\n");
        // }
        // else if(strcmp(opt, "post-order") == 0)
        // {
        //     if(arvoreVazia(a)) continue;

        //     int primeiro = 1;
        //     postOrderInline(raiz(a), &primeiro);
        //     printf("\n");
        // }
        // else if(strcmp(opt, "pre-order") == 0)
        // {
        //     if(arvoreVazia(a)) continue;

        //     int primeiro = 1;
        //     preOrderInline(raiz(a), &primeiro);
        //     printf("\n");
        // }
        else if (strcmp(opt, "maior") == 0)
        {
            No *maiorValor = maiorElemento(a->raiz);
            if (maiorValor != NULL)
                printf("%d", maiorValor->chave);
        }
        else if (strcmp(opt, "menor") == 0)
        {
            No *menorValor = menorElemento(a->raiz);
            if (menorValor != NULL)
                printf("%d", menorValor->chave);
        }
        else if(strcmp(opt, "in-order") == 0)
        {
            if(arvoreVazia(a)) continue;

            inOrder(raiz(a));
        }
        else if(strcmp(opt, "post-order") == 0)
        {
            if(arvoreVazia(a)) continue;

            postOrder(raiz(a));
        }
        else if(strcmp(opt, "pre-order") == 0)
        {
            if(arvoreVazia(a)) continue;

            int primeiro = 1;
            preOrder(raiz(a));
        }
    }
    return 0;
}

#pragma region "Listar na mesma linha"
void inOrderInline(No *r, int *primeiro)
{
    if(r == NULL)
        return;

    inOrderInline(r->esquerda, primeiro);
    if(*primeiro)
        *primeiro = 0;
    else
        printf(" ");

    printf("%c", r->chave);
    inOrderInline(r->direita, primeiro);
}

void postOrderInline(No *r, int *primeiro)
{
    if(r == NULL)
        return;

    postOrderInline(r->esquerda, primeiro);
    postOrderInline(r->direita, primeiro);
    if(*primeiro)
        *primeiro = 0;
    else
        printf(" ");
    
    printf("%c", r->chave);
}

void preOrderInline(No *r, int *primeiro)
{
    if(r == NULL)
        return;

    if(*primeiro)
        *primeiro = 0;
    else
        printf(" ");

    printf("%c", r->chave);
    preOrderInline(r->esquerda, primeiro);
    preOrderInline(r->direita, primeiro);
}
#pragma endregion

#pragma region "Listar 1 item por linha"
void inOrder(No *r)
{
    if(r != NULL)
    {
        inOrder(r->esquerda);
        printf("%c\n", r->chave);
        inOrder(r->direita);
    }
}

void postOrder(No *r)
{
    if(r != NULL)
    {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%c\n", r->chave);
    }
}

void preOrder(No *r)
{
    if(r != NULL)
    {
        printf("%c\n", r->chave);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
}
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

No *buscar(Arvore *a, char chave)
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

#pragma region  "Inserir/Remover"
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

No *remover(Arvore *a, char rem)
{
    No *pai = NULL, *filho = raiz(a);

    while(filho != NULL && filho->chave != rem)//Buscando valor pra remover
    {
        pai = filho;
        if(filho->chave > rem)
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
#pragma region "Sucessor/Antecessor"
No *sucessor(No *n)
{
    if(n != NULL)
    {
        No *suc = n->direita;
        while(suc->esquerda != NULL)
            suc = suc->esquerda;

        return suc;
    }
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
#pragma endregion

#pragma region "Maior e Menor"
No *maiorElemento(No *raiz)
{
    if (raiz == NULL)
        return NULL;

    while (raiz->direita != NULL)
        raiz = raiz->direita;
    
    return raiz;
}

No *menorElemento(No *raiz)
{
    if (raiz == NULL)
        return NULL;

    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;

    return raiz;
}
#pragma endregion

void removerSucessor(No *suc)
{
    if(suc != NULL)
    {
        No *pai = suc->pai;
        if(pai != NULL)
        {
            if(pai->esquerda == suc)
                pai->esquerda = suc->direita;
            else
                pai->direita = suc->direita;
        }

        if(suc->direita != NULL)
            suc->direita->pai = pai;

        suc->pai = NULL;
        suc->esquerda = NULL;
        suc->direita = NULL;
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