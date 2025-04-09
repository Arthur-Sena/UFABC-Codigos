#include <stdio.h>


    // float tempo;


int main() {
    int quantidade, trocas;
    int numero;
    char nome[41];
    char equipe[41];



    scanf("%d", &quantidade);
    float tempos[quantidade];

    for (int i = 0; i < quantidade; i++) {
        scanf("%d %s %s %f", &numero, nome, equipe, &tempos[i]);

    }

    trocas = 0;
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if(tempos[j] > tempos[j+1]) {
                float aux = tempos[j];
                tempos[j] = tempos[j + 1];
                tempos[j+1] = aux;
                trocas++;
            }

        }
    }

    
    printf("%d\n", trocas);

    return 0;
}