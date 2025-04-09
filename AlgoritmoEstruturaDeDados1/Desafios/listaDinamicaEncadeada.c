#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item {
    int valor;
    struct Item *proximo;
} Item;

typedef struct Lista {
    Item *primeiro;
} Lista;

Lista *criarLista() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL) {
        l->primeiro = NULL;
    }
    return l;
}

void liberarLista(Lista *l) {
    if (l == NULL) return;
    
    Item *atual = l->primeiro;
    while (atual != NULL) {
        Item *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(l);
}

void incluirElemento(Lista *l, int valor) {
    if (l == NULL) return;

    Item *novo = (Item *)malloc(sizeof(Item));
    if (novo == NULL) return;
    novo->valor = valor;
    novo->proximo = NULL;

    // Caso lista vazia ou novo valor é o menor
    if (l->primeiro == NULL || l->primeiro->valor > valor) {
        novo->proximo = l->primeiro;
        l->primeiro = novo;
        return;
    }

    // Buscar posição de inserção
    Item *atual = l->primeiro;
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    // Evitar duplicatas
    if (atual->valor == valor || (atual->proximo != NULL && atual->proximo->valor == valor)) {
        free(novo);
        return;
    }

    // Inserir novo item
    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

void excluir(Lista *l, int valor) {
    if (l == NULL || l->primeiro == NULL) return;

    Item *atual = l->primeiro;
    Item *anterior = NULL;

    // Encontrar o item a ser removido
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Item não encontrado
    if (atual == NULL) return;

    // Remover o item
    if (anterior == NULL) {
        l->primeiro = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

bool buscar(Lista *l, int valor) {
    if (l == NULL || l->primeiro == NULL) return false;

    Item *atual = l->primeiro;
    while (atual != NULL && atual->valor <= valor) {
        if (atual->valor == valor) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void listar(Lista *l) {
    if (l == NULL) return;

    Item *atual = l->primeiro;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(" ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Lista *l = criarLista();
    if (l == NULL) 
        return 0;

    char opcao;
    int valor;

    while (scanf(" %c", &opcao) != EOF) {
        switch (opcao) {
            case 'I':
                scanf("%d", &valor);
                incluirElemento(l, valor);
                break;
            case 'R':
                scanf("%d", &valor);
                excluir(l, valor);
                break;
            case 'B':
                scanf("%d", &valor);
                printf("%s\n", buscar(l, valor) ? "SIM" : "NAO");
                break;
            case 'L':
                listar(l);
                break;
            default:
                break;
        }
    }

    liberarLista(l);
    return 0;
}