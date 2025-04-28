#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    struct Node* pai;
    struct Node* noEsquerdo;
    int valor;
    struct Node* noDireito;
} Node;

typedef struct Tree
{
    Node* raiz;
} Tree;

void insert(Tree *t, Node *n);
void remover(Tree *t, int chave);
void preOrder(Node* n);
void inOrder(Node* n);
void postOrder(Node* n);
Node * sucessor(Node *r);
Node * removerSucessor(Node *r);

int main()
{
    Tree *a = (Tree *)malloc(sizeof(Tree));
    a->raiz = NULL;

    char opc[30];
    while (scanf("%s", opc) != EOF)
    {        
        int entrada;
        if (strcmp(opc, "insert") == 0)
        {
            scanf("%d", &entrada);
            Node *n = (Node*) malloc (sizeof(Node));
            n->noDireito = NULL;
            n->noEsquerdo = NULL;
            n->pai = NULL;
            n->valor = entrada;
            insert(a, n);
        }
        else if(strcmp(opc, "pre-order") == 0)
            preOrder(a->raiz);
        else if(strcmp(opc, "in-order") == 0)
            inOrder(a->raiz);
        else if(strcmp(opc, "post-order") == 0)
            postOrder(a->raiz);
        else if(strcmp(opc, "delete") == 0)
        {
            scanf("%d", &entrada);
            remover(a, entrada);
        }
    }

    return 0;
}

void insert(Tree *t, Node *n)
{
    if (t->raiz == NULL)
    {
        t->raiz = n;
        return;
    }

    Node *pai = NULL, *filho = t->raiz;
    while(filho != NULL)
    {
        pai = filho;
        if(filho->valor < n->valor)
            filho = filho->noDireito;
        else
            filho = filho->noEsquerdo;
    }

    n->pai = pai;
    if (pai->valor <= n->valor)
        pai->noDireito = n;
    else
        pai->noEsquerdo = n;    
}

void remover(Tree *t, int chave)
{
    if (t == NULL) return;

    Node *pai = NULL, *filho = t->raiz, *subs;

    while(filho != NULL && filho->valor != chave)
    {
        pai = filho;
        if(filho->valor < chave)
            filho = filho->noDireito;
        else
            filho = filho->noEsquerdo;
    }

    if(filho != NULL)
    {
        printf("%d\n", filho->valor);
        if(filho->noEsquerdo == NULL && filho->noDireito == NULL) 
        {
            if(pai != NULL) 
            {
                if(pai->noEsquerdo == filho)
                    pai->noEsquerdo = NULL;
                else
                    pai->noDireito = NULL;
            }
            else
                t->raiz = NULL;
        }
        else if(filho->noEsquerdo != NULL && filho->noDireito != NULL) 
        {
            subs = removerSucessor(sucessor(filho));

            subs->pai = pai;
            subs->noEsquerdo = filho->noEsquerdo;
            subs->noDireito = filho->noDireito;

            if(pai != NULL)
                if(pai->noEsquerdo == filho)
                    pai->noEsquerdo = subs;
                else
                    pai->noDireito = subs;
            else
                t->raiz = subs;
            
            if(filho->noEsquerdo != NULL)
                filho->noEsquerdo->pai = subs;
            
            if(filho->noDireito != NULL)
                filho->noDireito->pai = subs;
        }
        else 
        {
            if(pai != NULL) 
            {
                if(pai->noEsquerdo == filho)
                {
                    if(filho->noEsquerdo != NULL)
                    {
                        pai->noEsquerdo = filho->noEsquerdo;
                        filho->noEsquerdo->pai = pai;
                    }
                    else
                    {
                        pai->noEsquerdo = filho->noDireito;
                        filho->noDireito->pai = pai;
                    }
                }
                else
                {
                    if(filho->noEsquerdo != NULL)
                    {
                        pai->noDireito = filho->noEsquerdo;
                        filho->noEsquerdo->pai = pai;
                    }
                    else
                    {
                        pai->noDireito = filho->noDireito;
                        filho->noDireito->pai = pai;
                    }
                }
            }
            else
            {
                if(filho->noEsquerdo != NULL)
                {
                    t->raiz = filho->noEsquerdo;
                    filho->noEsquerdo->pai = NULL;
                }
                else
                {
                    t->raiz = filho->noDireito;
                    filho->noDireito->pai = NULL;
                }
            }
        }
        filho->pai = NULL;
        filho->noEsquerdo = NULL;
        filho->noDireito = NULL;
    }
}

void preOrder(Node *n)
{
    if(n == NULL)
        return;

    printf("%d\n", n->valor);
    preOrder(n->noEsquerdo);
    preOrder(n->noDireito);
}

void inOrder(Node *n)
{
    if(n == NULL)
        return;

    inOrder(n->noEsquerdo);
    printf("%d\n", n->valor);
    inOrder(n->noDireito);
}

void postOrder(struct Node *n)
{
    if(n == NULL)
        return;

    postOrder(n->noEsquerdo);
    postOrder(n->noDireito);
    printf("%d\n", n->valor);    
}

Node* sucessor(Node *r)
{
    if (r == NULL) return NULL;

    Node *pai = NULL;
    r = r->noDireito;
    while(r != NULL)
    {
        pai = r;
        r = r->noEsquerdo;
    }
    return pai;
}

Node * removerSucessor(Node *r)
{
    if (r == NULL || r->pai == NULL) return NULL;
    
    Node *pai = r->pai;
    if(pai->noEsquerdo == r)
        pai->noEsquerdo = r->noDireito;
    else
        pai->noDireito = r->noDireito;

    if(r->noDireito != NULL)
        r->noDireito->pai = pai;

    r->pai = NULL;
    r->noDireito = NULL;
    return r;
}