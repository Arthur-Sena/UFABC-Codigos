#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct No
{
    struct No *pai;
    struct No *noEsquerdo;
    int valor;
    struct No *noDireito;
} No;

typedef struct Arvore
{
    No *raiz;
} Arvore;

No *criarNo(int valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->noDireito = NULL;
    novoNo->noEsquerdo = NULL;
    novoNo->pai = NULL;
    novoNo->valor = valor;
    return novoNo;
}
#pragma region "Interface"
void inserir(Arvore *t, No *n);
No* remover (int valor, No* raiz);

No *maiorElemento(No *raiz);
No *menorElemento(No *raiz);

void preOrder(No *n); //Com /n
void inOrder(No *n);//Com /n
void postOrder(No *n);//Com /n
void preOrderInline(No *n, int *); //inline
void inOrderInline(No *n, No* lastNode); //inline
void postOrderInline(No *n, No* raiz); //inline

int busca(No* raiz, int valor);
int arvoreVazia(Arvore *a);
No * raiz(Arvore *);
// void reverso(Arvore raiz);
// int altura(Arvore raiz);
// int qntdFolhas(Arvore raiz);
// void caminho(Arvore raiz, int valor);
#pragma endregion

int main()
{
    Arvore *a = (Arvore *)malloc(sizeof(Arvore));
    a->raiz = NULL;

    char opc[30];
    while (scanf("%s", opc) != EOF)
    {
        int entrada;
        if (strcmp(opc, "insert") == 0)
        {
            scanf("%d", &entrada);
            No *n = criarNo(entrada);
            inserir(a, n);
        }
        else if (strcmp(opc, "maior") == 0)
        {
            No *maiorValor = maiorElemento(a->raiz);
            if (maiorValor != NULL)
                printf("%d", maiorValor->valor);
        }
        else if (strcmp(opc, "menor") == 0)
        {
            No *menorValor = menorElemento(a->raiz);
            if (menorValor != NULL)
                printf("%d", menorValor->valor);
        }
        else if (strcmp(opc, "pre-order") == 0)
        {
            if(!arvoreVazia(a))
            {
                int primeiro = 1;
                preOrderInline(a->raiz, &primeiro);
                printf("\n");
            }
        }
        else if (strcmp(opc, "in-order") == 0)
        {
            if(!arvoreVazia(a))
            {
                inOrderInline(a->raiz, maiorElemento(a->raiz));
            }
        }
        else if (strcmp(opc, "post-order") == 0)
        {
            if(!arvoreVazia(a))
            {
                postOrderInline(a->raiz, a->raiz);
            }
        }
        else if (strcmp(opc, "delete") == 0)
        {
            scanf("%d", &entrada);
            if (busca(a->raiz, entrada) > 0)
                printf("%d\n", entrada);
            a->raiz = remover(entrada, a->raiz);
        }
    }

    return 0;
}

#pragma region  "Auxiliares (raiz, isVazia e Buscar)"
No *raiz(Arvore *a)
{
    return a->raiz;
}

int arvoreVazia(Arvore *a)
{
    return raiz(a) == NULL;
}

int busca (No* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    if(raiz->valor == valor){
        return 1;
    }
    if(valor >= raiz->valor){
        return busca(raiz->noDireito, valor);
    }
    return busca(raiz->noEsquerdo, valor);
}
#pragma endregion

#pragma region "Listar com \n"
void preOrder(No *n)
{
    if (n == NULL)
        return;

    printf("%d\n", n->valor);
    preOrder(n->noEsquerdo);
    preOrder(n->noDireito);
}

void inOrder(No *n)
{
    if (n == NULL)
        return;

    inOrder(n->noEsquerdo);
    printf("%d\n", n->valor);
    inOrder(n->noDireito);
}

void postOrder(struct No *n)
{
    if (n == NULL)
        return;

    postOrder(n->noEsquerdo);
    postOrder(n->noDireito);
    printf("%d\n", n->valor);
}
#pragma endregion

#pragma region "Listar inline"
void preOrderInline(No *n, int* primeiro)
{
    if (n == NULL)
        return;

    if(*primeiro)
        *primeiro = 0;
    else
        printf(" ");
    printf("%d", n->valor);
    preOrderInline(n->noEsquerdo, primeiro);
    preOrderInline(n->noDireito, primeiro);
}

void inOrderInline(No *n, No* lastNode)
{
    if (n == NULL)
        return;

    inOrderInline(n->noEsquerdo, lastNode);

    if (lastNode != NULL && n == lastNode)
        printf("%d\n", n->valor);
    else
        printf("%d ", n->valor);

    inOrderInline(n->noDireito, lastNode);
}

void postOrderInline(struct No *n, No *raiz)
{
    if (n == NULL)
        return;

    postOrderInline(n->noEsquerdo, raiz);
    postOrderInline(n->noDireito, raiz);
    if (n == raiz)
        printf("%d\n", n->valor);
    else
        printf("%d ", n->valor);
}
#pragma endregion

#pragma region "Maior e Menor"
No *maiorElemento(No *raiz)
{
    if (raiz == NULL)
        return NULL;

    while (raiz->noDireito != NULL)
    {
        raiz = raiz->noDireito;
    }
    return raiz;
}

No *menorElemento(No *raiz)
{
    if (raiz == NULL)
        return NULL;

    while (raiz->noEsquerdo != NULL)
    {
        raiz = raiz->noEsquerdo;
    }
    return raiz;
}
#pragma endregion

void inserir(Arvore *t, No *n)
{
    if (t == NULL || n == NULL) return;
    if (t->raiz == NULL)
    {
        t->raiz = n;
        return;
    }

    No *pai = NULL, *filho = t->raiz;
    while (filho != NULL)
    {
        pai = filho;
        if (filho->valor <= n->valor)
            filho = filho->noDireito;
        else
            filho = filho->noEsquerdo;
    }
    
    if (pai == NULL) return;

    n->pai = pai;
    if (pai->valor <= n->valor)
        pai->noDireito = n;
    else
        pai->noEsquerdo = n;
}

No* remover (int valor, No* raiz){
    //se a arvore for vazia, ou se o elemento não estiver na arvore
    if (raiz == NULL)
        return NULL;

    if (valor > raiz->valor) //se o valor for maior, busca na subarvore a direita
        raiz->noDireito = remover(valor, raiz->noDireito);
    else if (valor < raiz->valor) //se o valor for menor, busca na subarvore a esquerda
        raiz->noEsquerdo = remover(valor, raiz->noEsquerdo);    
    
    else //caso encontre o valor, remove 
    {
        //CASO 01. o elemento é uma folha. remove e att o ponteiro do pai
        if(raiz->noDireito == NULL && raiz->noEsquerdo == NULL){
            free(raiz);
            return NULL;
        }
        //CASO 02.A. o elemento possui exatamente um filho direito
        else if(raiz->noDireito != NULL && raiz->noEsquerdo == NULL){
            No* aux = raiz;
            raiz = raiz->noDireito;
            free (aux);
            return raiz;
        }
        //CASO 02.B. o elemento possui exatamente um filho esquerdo
        else if(raiz->noEsquerdo != NULL && raiz->noDireito == NULL){
            No* aux = raiz;
            raiz = raiz->noEsquerdo;
            free (aux);
            return raiz;
        }
        //CASO 03. o elemento possui 2 filhos
        else if(raiz->noDireito != NULL && raiz->noEsquerdo !=NULL){
            No* elemento = menorElemento(raiz->noDireito);
            raiz->valor = elemento->valor;
            raiz->noDireito = remover(elemento->valor, raiz->noDireito);
        }
    }
    return raiz;
}