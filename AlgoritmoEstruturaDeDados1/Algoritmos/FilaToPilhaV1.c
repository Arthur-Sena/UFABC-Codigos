#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estrutura do item da pilha
typedef struct ItemPilha {
    int valor;
    struct ItemPilha *anterior;
} ItemPilha;

// Estrutura da pilha
typedef struct Pilha {
    ItemPilha *topo;
    int tamanho;
} Pilha;

// Estrutura do item da fila
typedef struct ItemFila {
    int valor;
    struct ItemFila *proximo;
} ItemFila;

// Estrutura da fila
typedef struct Fila {
    ItemFila *primeiro;
    ItemFila *ultimo;
    int tamanho;
} Fila;

// Cria uma nova fila vazia
Fila* criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) return NULL;
    
    f->primeiro = NULL;
    f->ultimo = NULL;
    f->tamanho = 0;
    return f;
}

// Cria uma nova pilha vazia
Pilha* criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) return NULL;
    
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

// Libera a memória da fila
void liberarFila(Fila *f) {
    if (f == NULL) return;
    
    ItemFila *atual = f->primeiro;
    while (atual != NULL) {
        ItemFila *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(f);
}

// Libera a memória da pilha
void liberarPilha(Pilha *p) {
    if (p == NULL) return;
    
    ItemPilha *atual = p->topo;
    while (atual != NULL) {
        ItemPilha *temp = atual;
        atual = atual->anterior;
        free(temp);
    }
    free(p);
}

// Adiciona um elemento no final da fila
bool enfileirar(Fila *f, int valor) {
    if (f == NULL) return false;
    
    ItemFila *novo = (ItemFila*)malloc(sizeof(ItemFila));
    if (novo == NULL) return false;
    
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (f->ultimo == NULL) {
        f->primeiro = novo;
    } else {
        f->ultimo->proximo = novo;
    }
    f->ultimo = novo;
    f->tamanho++;
    
    return true;
}

// Remove o primeiro elemento da fila
bool desenfileirar(Fila *f) {
    if (f == NULL || f->primeiro == NULL) return false;
    
    ItemFila *removido = f->primeiro;
    f->primeiro = f->primeiro->proximo;
    
    if (f->primeiro == NULL) 
        f->ultimo = NULL;
    
    free(removido);
    f->tamanho--;
    return true;
}

// Lista os elementos da fila
void listarFila(Fila *f) {
    if (f == NULL || f->primeiro == NULL) {
        printf("Fila vazia\n");
        return;
    }
    
    ItemFila *atual = f->primeiro;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(" ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

// Empilha um elemento
bool empilhar(Pilha *p, int valor) {
    if (p == NULL) return false;
    
    ItemPilha *novo = (ItemPilha*)malloc(sizeof(ItemPilha));
    if (novo == NULL) return false;
    
    novo->valor = valor;
    novo->anterior = p->topo;
    p->topo = novo;
    p->tamanho++;
    
    return true;
}

// Desempilha um elemento
bool desempilhar(Pilha *p) {
    if (p == NULL || p->topo == NULL) return false;
    
    ItemPilha *removido = p->topo;
    p->topo = p->topo->anterior;
    
    free(removido);
    p->tamanho--;
    return true;
}

// Lista os elementos da pilha (do topo para a base)
void listarPilha(Pilha *p) {
    if (p == NULL || p->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }
    
    ItemPilha *atual = p->topo;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->anterior != NULL) {
            printf(" ");
        }
        atual = atual->anterior;
    }
    printf("\n");
}

// Converte a fila em uma pilha (invertendo a ordem)
bool filaParaPilha(Fila *f, Pilha *p) {
    if (f == NULL || p == NULL) return false;
    
    // Limpa a pilha atual
    while (p->topo != NULL) {
        desempilhar(p);
    }
    
    // Primeiro criamos uma pilha temporária para inverter a ordem
    Pilha *temp = criarPilha();
    if (temp == NULL) return false;
    
    // Empilhamos todos os elementos da fila na pilha temporária
    // Isso inverterá a ordem natural da fila
    ItemFila *atual = f->primeiro;
    while (atual != NULL) {
        if (!empilhar(temp, atual->valor)) {
            liberarPilha(temp);
            return false;
        }
        atual = atual->proximo;
    }
    
    // Agora desempilhamos da pilha temporária e empilhamos na pilha final
    // Isso fará com que o primeiro da fila fique no topo da pilha
    while (temp->topo != NULL) {
        if (!empilhar(p, temp->topo->valor)) {
            liberarPilha(temp);
            return false;
        }
        desempilhar(temp);
    }
    
    liberarPilha(temp);
    return true;
}

int main() {
    Fila *f = criarFila();
    Pilha *p = criarPilha();
    
    if (f == NULL || p == NULL) {
        fprintf(stderr, "Erro ao alocar memoria\n");
        liberarFila(f);
        liberarPilha(p);
        return EXIT_FAILURE;
    }
    
    char opcao;
    int valor;
    
    while (scanf(" %c", &opcao) != EOF) {
        switch (opcao) {
            case 'E': // Enfileirar
                if (scanf("%d", &valor) != 1) {
                    fprintf(stderr, "Erro ao ler valor\n");
                    continue;
                }
                if (!enfileirar(f, valor))
                    fprintf(stderr, "Erro ao enfileirar\n");                
                break;                
            case 'D': // Desenfileirar
                if (!desenfileirar(f)) 
                    fprintf(stderr, "Erro ao desenfileirar (fila vazia?)\n");                
                break;                
            case 'L': // Listar fila
                listarFila(f);
                break;                
            case 'P': // Converter fila para pilha
                if (!filaParaPilha(f, p))
                    fprintf(stderr, "Erro ao converter fila para pilha\n");
                break;
            case 'M': // Mostrar pilha
                listarPilha(p);
                break;
            default:
                break;
        }
    }
    
    liberarFila(f);
    liberarPilha(p);
}