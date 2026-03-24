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
void mostrarFolhas(No *);

int main()
{
  Arvore *a = criarArvore();

  while(1 == 1)
  {
    int new_value;
    scanf("%d", &new_value);
    if (new_value < 0)
      break;

    if (buscar(a, new_value) != NULL)
      continue;

    No* novo = criarNo(new_value);
    inserir(a, novo);
  }
  mostrarFolhas(raiz(a));
  return 0;
}

void mostrarFolhas(No * node)
{
  if(node != NULL)
  {
    mostrarFolhas(node->direita);
    if(node->direita == NULL && node->esquerda == NULL)
      printf("%d\n", node->chave);
    mostrarFolhas(node->esquerda);
  }
}

#pragma region "Criar Nó/Arvore"
No *criarNo(int chave)
{
    No *it = (No *)malloc(sizeof(No));
    if (it == NULL)
        return NULL;

    it->chave = chave;
    it->pai = NULL;
    it->esquerda = NULL;
    it->direita = NULL;

    return it;
}

Arvore *criarArvore()
{
    Arvore *a = (Arvore *)malloc(sizeof(Arvore));
    if (a != NULL)
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

No *buscar(Arvore *a, int chave)
{
    No *no = raiz(a);

    while (no != NULL && no->chave != chave)
    {
        if (no->chave < chave)
            no = no->direita;
        else
            no = no->esquerda;
    }
    return no;
}

void inserir(Arvore *a, No *novo)
{
    No *pai = NULL, *filho = raiz(a);

    while (filho != NULL)
    {
        pai = filho;
        if (filho->chave >=  novo->chave)
            filho = filho->esquerda;
        else
            filho = filho->direita;
    }

    if (pai != NULL)
    {
        novo->pai = pai;
        if (pai->chave >=  novo->chave)
            pai->esquerda = novo;
        else
            pai->direita = novo;
    }
    else
        a->raiz = novo;
}