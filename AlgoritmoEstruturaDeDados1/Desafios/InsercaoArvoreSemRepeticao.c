#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool chaveJaExiste(int* arvore, int chave, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        if (arvore[i] == chave)
        {
            printf("Chave %d ja existe na arvore!\n", chave);
            return true;
        }    
    
    return false;
}

int main(){
    int qntEntrada;
    scanf("%d", &qntEntrada);

    int *arvore = (int*) malloc (qntEntrada * sizeof(int));
    int id = 0;
    for(int i = 0; i<qntEntrada; i++)
    {
        int entrada;
        scanf("%d", &entrada);
        
        if (chaveJaExiste(arvore, entrada, qntEntrada))
            continue;
        else
        {
            arvore[id] = entrada;
            id++;
        }
    }

    return 0;
}