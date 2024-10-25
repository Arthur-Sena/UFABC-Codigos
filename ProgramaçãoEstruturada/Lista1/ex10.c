#include <stdio.h>

int minimo( int v [] , int n) {
    int m = v[0];
    for(int i = 0; i < n; i++){
        if(v[i] < m)
            m = v[i];
    }
    printf("O menor numero do vetor é: %d\n", m);
}

int maximo( int v [] , int n){
    int m = v[0];
    for(int i = 0; i < n; i++){
        if(v[i] > m)
            m = v[i];
    }
    printf("O maior numero do vetor é: %d\n", m);
}

double media( int v [] , int n ) {
    int sm = 0;
    int med;
    for(int i = 0; i < n; i++)
        sm += v[i];

    med = sm/n;
    printf("A media dos numeros do vetor é: %d\n", med);
}

void le_vetor( int entrada [] , int n) {
    for(int i = 0; i < n; i++){
        printf("Entre com o %dº Valor do Vetor: ", i+1);
        scanf("%d", &entrada[i]);
    }

    minimo(entrada, n);
    maximo(entrada, n);
    media(entrada, n);
}

int main() {
    int lista[99];
    
    int tamanho;
    printf("Digite um número: ");
	scanf("%d", &tamanho);
    
    le_vetor(lista, tamanho);
    
    return 0;
}