#include <stdio.h>
#include <stdlib.h>

struct tNo
{
    int chave;
    struct tNo * pai;
    struct tNo * direita;
    struct tNo * esquerda;
};

struct tArvore
{
    struct tNo * raiz;
};

struct tNo * criarNo(int);
struct tArvore * criarArvore();
struct tNo * raiz(struct tArvore *);
int arvoreVazia(struct tArvore *);
void preOrder(struct tNo *);
void inOrder(struct tNo *);
void postOrder(struct tNo *);
struct tNo * buscar(struct tArvore *, int);
void inserir(struct tArvore *, struct tNo *);
struct tNo * remover(struct tArvore *, int);
struct tNo * sucessor(struct tNo *);
struct tNo * removerSucessor(struct tNo *);

int main()
{
    int opc, chave;
    struct tNo *it;
    struct tArvore *arvore = criarArvore();

    do
    {
        do
        {
            printf("Escolha uma das opcoes a seguir:\n");
            printf("1 - Inserir na Arvore\n");
            printf("2 - Mostrar Arvore (Pre-Order)\n");
            printf("3 - Mostrar Arvore (In-Order)\n");
            printf("4 - Mostrar Arvore (Post-Order)\n");
            printf("5 - Raiz da Arvore\n");
            printf("6 - Buscar na Arvore\n");
            printf("7 - Remover da Arvore\n");
            printf("8 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        }while(opc < 1 || opc > 8);

        if(opc == 1 || opc == 6 || opc == 7)
        {
            printf("Informe o valor da chave: ");
            scanf("%d", &chave);
        }

        switch(opc)
        {
            case 1: inserir(arvore, criarNo(chave));
                    break;
            case 2: preOrder(raiz(arvore));
                    break;
            case 3: inOrder(raiz(arvore));
                    break;
            case 4: postOrder(raiz(arvore));
                    break;
            case 5: if(!arvoreVazia(arvore))
                    {
                        printf("Item %d estah na raiz da arvore!\n", raiz(arvore)->chave);
                    }
                    break;
            case 6: printf("Item %d%slocalizado na arvore!\n", chave, buscar(arvore, chave) != NULL ? " " : " NAO ");
                    break;
            case 7: it = remover(arvore, chave);
                    if(it != NULL)
                    {
                        printf("Item %d removido da arvore!\n", it->chave);
                        free(it);
                    }
        }
    }while(opc != 8);
    printf("SALVEM AS ARVORES!\n");
    return 0;
}

struct tNo * criarNo(int chave)
{
    struct tNo *no = (struct tNo *) malloc(sizeof(struct tNo));
    if(no != NULL)
    {
        no->chave = chave;
        no->pai = NULL;
        no->direita = NULL;
        no->esquerda = NULL;
    }
    return no;
}

struct tArvore * criarArvore()
{
    struct tArvore *t = (struct tArvore *) malloc(sizeof(struct tArvore));
    if(t != NULL)
    {
        t->raiz = NULL;
    }
    return t;
}

struct tNo * raiz(struct tArvore *t)
{
    return t->raiz;
}

int arvoreVazia(struct tArvore *t)
{
    return raiz(t) == NULL;
}

void preOrder(struct tNo *r)
{
    if(r != NULL)
    {
        printf("%d\n", r->chave);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
}

void inOrder(struct tNo *r)
{
    if(r != NULL)
    {
        inOrder(r->esquerda);
        printf("%d\n", r->chave);
        inOrder(r->direita);
    }
}

void postOrder(struct tNo *r)
{
    if(r != NULL)
    {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%d\n", r->chave);
    }
}

struct tNo * buscar(struct tArvore *t, int chave)
{
    struct tNo *no = raiz(t);

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

void inserir(struct tArvore *t, struct tNo *novo)
{
    struct tNo *pai = NULL, *filho = raiz(t);

    while(filho != NULL)
    {
        pai = filho;
        if(filho->chave < novo->chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(pai != NULL) // nao eh raiz
    {
        novo->pai = pai;
        if(pai->chave < novo->chave)
        {
            pai->direita = novo;
        }
        else
        {
            pai->esquerda = novo;
        }
    }
    else // eh raiz
    {
        t->raiz = novo;
    }
}

struct tNo * remover(struct tArvore *t, int chave)
{
    struct tNo *pai = NULL, *filho = raiz(t);

    while(filho != NULL && filho->chave != chave)
    {
        pai = filho;
        if(filho->chave < chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) // encontrei
    {
        if(filho->esquerda == NULL && filho->direita == NULL) // removendo uma folha
        {
            if(pai != NULL) // nao eh raiz
            {
                if(pai->esquerda == filho)
                {
                    pai->esquerda = NULL;
                }
                else
                {
                    pai->direita = NULL;
                }
            }
            else // eh raiz
            {
                t->raiz = NULL;
            }
        }
        else if(filho->esquerda != NULL && filho->direita != NULL) // removendo um pai de dois filhos
        {

        }
        else // removendo o pai de um filho unico
        {
            if(pai != NULL) // nao eh raiz
            {
                if(pai->esquerda == filho) // no a ser removido eh filho da esquerda do pai
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
                else // no a ser removido eh filho da direita do pai
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
            else // eh raiz
            {
                if(filho->esquerda != NULL)
                {
                    t->raiz = filho->esquerda;
                    filho->esquerda->pai = NULL;
                }
                else
                {
                    t->raiz = filho->direita;
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

struct tNo * sucessor(struct tNo *r)
{
    struct tNo * pai = NULL;
    r = r->direita;
    while(r != NULL)
    {
        pai = r;
        r = r->esquerda;
    }
    return r;
}

struct tNo * removerSucessor(struct tNo *r)
{
    struct tNo *pai = r->pai;

    if(r->esquerda == NULL && r->direita == NULL) //eh folha
    {
        if(pai->esquerda == r)
        {
            pai->esquerda = NULL;
        }
        else
        {
            pai->direita = NULL;
        }
    }
    else // eh pai de um
    {
        if(pai->esquerda == r)
        {
            pai->esquerda = r->direita;
        }
        else
        {
            pai->direita = r->direita;
        }
        r->direita->pai = pai; // tem que ver se nao vai dar RTE
    }
}