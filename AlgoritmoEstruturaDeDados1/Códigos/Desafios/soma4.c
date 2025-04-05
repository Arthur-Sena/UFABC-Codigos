#include <stdio.h>

int main(){
    long qntRepeticao;
    scanf("%d", &qntRepeticao);

    for(int j = 0; j < qntRepeticao; j++)
    {

        int tamanhoLista;
        long totalSoma = 0, num = 0;
        scanf("%d", &tamanhoLista);
        
        for(int i = 0; i < tamanhoLista; i++)
        {
            scanf("%ld", &num);
            totalSoma += num;
        }
        
        printf("%ld\n", totalSoma);
    }
    return 0;
}