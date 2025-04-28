#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
}No;

typedef No *arvore;

arvore inserir(int valor, arvore raiz);
arvore maiorElemento(arvore raiz);
arvore remover(int valor, arvore raiz);
void preorder (arvore raiz);
void inorder (arvore raiz);
void posorder (arvore raiz);
void reverso (arvore raiz);
int altura (arvore raiz);
int qntdFolhas (arvore raiz);
int busca (arvore raiz, int valor);
void caminho (arvore raiz, int valor);

int main(){
    arvore raiz = NULL;
    int loop = 1;
    int opc = 0;
    int valor = 0;
    printf("******MENU******\n");
    printf("1- INSERIR\n");
    printf("2- PREORDER\n");
    printf("3- INORDER\n");
    printf("4- POSORDER\n");
    printf("5- REVERSO\n");
    printf("6- ALTURA\n");
    printf("7- QUANTIDADE DE FOLHAS\n");
    printf("8- CAMINHO\n");
    printf("9- REMOVER\n");
    printf("99 - SAIR\n");

    while(loop){

        scanf("%d", &opc);

        switch (opc){
        case 1:
            //1- INSERIR
            scanf("%d", &valor);
            raiz = inserir(valor, raiz);
            break;
        case 2:
            //2- PREORDER
            preorder(raiz);
            printf("\n");
            break;
        case 3:
            //3- INORDER
            inorder(raiz);
            printf("\n");
            break;
        case 4:
            //4- POSORDER
            posorder(raiz);
            printf("\n");
            break;
        case 5:
            //5- REVERSO
            reverso(raiz);
            printf("\n");
            break;
        case 6:
            //6- ALTURA
            printf("%d", altura(raiz));
            printf("\n");
            break;
        case 7:
            //7- QUANTIDADE DE FOLHAS
            printf("%d", qntdFolhas(raiz));
            printf("\n");
            break;
        case 8:
            //8- CAMINHO
            scanf("%d", &valor);
            caminho(raiz, valor);
            printf("\n");
            break;
        case 9:
            //9- REMOVER
            scanf("%d", &valor);
            raiz = remover(valor, raiz);
            break;
        case 99:
            loop = 0;
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

    }
    return 0;
}

arvore inserir(int valor, arvore raiz){
    if(raiz == NULL){
        arvore novo = (arvore)(malloc(sizeof(No)));
        novo->valor = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    } 

    if(valor >= raiz->valor)
        raiz->dir = inserir(valor, raiz->dir);
    else
        raiz->esq = inserir(valor, raiz->esq);
    
    return raiz;
}

arvore maiorElemento(arvore raiz){
    while (raiz->dir != NULL){
        raiz = raiz->dir;
    }
    return raiz;
}

arvore remover (int valor, arvore raiz){
    //se a arvore for vazia, ou se o elemento não estiver na arvore
    if (raiz == NULL){
        return NULL;
    }

    //se o valor for maior, busca na subarvore a direita
    if (valor > raiz->valor){
        raiz->dir = remover(valor, raiz->dir);
    } 

    //se o valor for menor, busca na subarvore a esquerda
    else if (valor < raiz->valor){
        raiz->esq = remover(valor, raiz->esq);
    } 
    
    //caso encontre o valor, remove
    else {
        //CASO 01. o elemento é uma folha. remove e att o ponteiro do pai
        if(raiz->dir == NULL && raiz->esq == NULL){
            free(raiz);
            return NULL;
        }
        //CASO 02.A. o elemento possui exatamente um filho direito
        if(raiz->dir != NULL && raiz->esq == NULL){
            arvore aux = raiz;
            raiz = raiz->dir;
            free (aux);
            return raiz;
        }

        //CASO 02.B. o elemento possui exatamente um filho esquerdo
        if(raiz->esq != NULL && raiz->dir == NULL){
            arvore aux = raiz;
            raiz = raiz->esq;
            free (aux);
            return raiz;
        }

        //CASO 03. o elemento possui 2 filhos
        if(raiz->dir != NULL && raiz->esq !=NULL){
            arvore elemento = maiorElemento(raiz->esq);
            raiz->valor = elemento->valor;
            raiz->esq = remover(elemento->valor, raiz->esq);
        }

    }
    return raiz;
}

void preorder (arvore raiz){
    if (raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void inorder(arvore raiz){
    if(raiz != NULL) {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}

void posorder(arvore raiz) {
    if(raiz != NULL) {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

void reverso(arvore raiz) {
    if (raiz != NULL) {
        reverso(raiz->dir);
        printf("[%d]", raiz->valor);
        reverso(raiz->esq);
    }
}

int altura(arvore raiz){
    if(raiz == NULL){
        return 0;
    }
    int alturaesquerda = altura(raiz->esq);
    int alturadireita = altura(raiz->dir);

    if(alturaesquerda >= alturadireita){
        return  1 + alturaesquerda;
    }
    return 1 + alturadireita;
}

int qntdFolhas(arvore raiz){
    if(raiz == NULL){
        return 0;
    }

    if (raiz->dir == NULL && raiz->esq == NULL){
        return 1;
    }

    return qntdFolhas(raiz->dir) + qntdFolhas(raiz->esq);
}

int busca (arvore raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    if(raiz->valor == valor){
        return 1;
    }
    if(valor > raiz->valor){
        return busca(raiz->dir, valor);
    }
    return busca(raiz->esq, valor);
}

void caminho (arvore raiz, int valor){
    if(busca(raiz, valor)){
        if(raiz == NULL){
            return;
        }
        if(raiz->valor == valor){
            printf("[%d]", raiz->valor);
        }
        if(raiz->valor > valor){
            printf("[%d]", raiz->valor);
            caminho(raiz->esq, valor);
        }
        else if(raiz->valor < valor){
            printf("[%d]", raiz->valor);
            caminho(raiz->dir, valor);
        }
    }
}