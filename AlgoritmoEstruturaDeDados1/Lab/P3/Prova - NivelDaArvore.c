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
void mostrarNivelK(No *no, int k);

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

  int nivelBusca;

  while(scanf("%d", &nivelBusca) != EOF)
  {
    if (arvoreVazia(a))
      continue;
    mostrarNivelK(raiz(a), nivelBusca);
  }

  return 0;
}

void mostrarNivelK(No *node, int nivel)
{
  if (node == NULL)
    return;

  if (nivel == 0)
  {
    printf("%d\n",node->chave);
    return;
  }
  
  mostrarNivelK(node->direita, nivel-1);
  mostrarNivelK(node->esquerda, nivel-1);
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