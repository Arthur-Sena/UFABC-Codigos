#include <stdio.h>
#include <string.h>

#define maxCaracteres 51

void imprimeVetor(int N, char vet[][maxCaracteres]) {
    printf("%s", vet[0]);
    for (int i = 1; i < N; i++) {
        printf(" %s", vet[i]);
    }
    printf("\n");
}

int ordenacaoBublle(int N, int fim, char vet[][maxCaracteres], int trocas) {
    char chave[maxCaracteres];

    if (fim==0){
        imprimeVetor(N, vet);
        printf("Trocas: %d\n",trocas);
        return 0;
    } else {
        for (int i=0; i<fim; i++){
            if (strcmp(vet[i],vet[i+1])>0){
                strcpy(chave, vet[i]);
                strcpy(vet[i],vet[i+1]);
                strcpy(vet[i+1],chave);
                imprimeVetor(N, vet);
                trocas++;
            }
        }
        fim=fim-1;
        trocas += ordenacaoBublle(N,fim,vet,trocas);
    }
    return trocas;
}

int main (){
    int N;
    scanf("%d", &N);
    
    int fim=(N-1), trocas=0;
    char vet[N][maxCaracteres];
    for (int i=0; i<N; i++){
        scanf("%s", vet[i]);
    }
    imprimeVetor(N, vet);
    ordenacaoBublle(N,fim,vet,trocas);

}