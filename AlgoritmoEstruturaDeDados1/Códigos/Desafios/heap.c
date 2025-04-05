#include <stdio.h>
#include <stdlib.h>
/*
    Filho esquerdo: 2*i+1
    Filho diteito: 2*i+2

    Pai: (i-1)/2.
    Ultimo pai: (n/2)-1:

    Qualquer nó com indice é folha= (n/2) <= i < n
*/
int main()
{
    int tamanhoVetor;
    scanf("%d", &tamanhoVetor);

    int *vetor = (int *)malloc(tamanhoVetor * sizeof(int *));
    for (int i = 0; i < tamanhoVetor; i++)
        scanf("%d", &vetor[i]);

    int idUltimoNo = (tamanhoVetor / 2) -1;
    for (int i = idUltimoNo; i >= 0; i--)
    {
        int valorPai = vetor[i];
        int filhoEsquerdo = (2*i + 1) < tamanhoVetor ? vetor[2*i + 1] : 0;;
        int filhoDireito = (2*i + 2) < tamanhoVetor ? vetor[2*i + 2] : 0;
        if (valorPai < filhoEsquerdo || valorPai < filhoDireito)
        {
            vetor[i] = filhoEsquerdo > filhoDireito ? filhoEsquerdo : filhoDireito;
            if (vetor[2*i + 1] > vetor[2*i + 2])
            {
                vetor[2*i + 1] = valorPai;
                i = 2*i + 1;
            }            
            else 
            {
                vetor[2*i + 2] = valorPai;
                i = 2*i + 2;            
            }
        } 
    }

    for (int i = 0; i < tamanhoVetor; i++)
        printf(i < tamanhoVetor-1 ? "%d " : "%d\n", vetor[i]);

    return 0;
}