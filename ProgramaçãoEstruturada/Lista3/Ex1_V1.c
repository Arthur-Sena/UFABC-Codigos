#include <stdio.h>

int busca_binaria(int valores[], int n, int chave)
{
    int inicio = 0;
    int fim = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (inicio == fim)
            break;
        
        int meio = (inicio + fim) / 2;
        if (valores[meio] >= chave)
            fim = meio;
        else
            inicio = meio + 1;
    }
    return inicio;
}

int main()
{
    int v[1000];
    int n, chave;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);

    printf("Inicialização do Vetor (digitar em ordem crescente) :\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nVETOR - Digite o valor da posição %d° :", i + 1);
        scanf("%d", &v[i]);
        if (i > 0 && v[i] < v[i - 1])
        {
            printf("\n - WARNING - Digite novamente o valor da posição %d° :", i + 1);
            scanf("%d", &v[i]);
        }
    }

    printf("Digite o valor da chave:\n");
    scanf("%d", &chave);

    int ret;
    ret = busca_binaria(v, n, chave);
    printf("\nRESULTADO POSIÇÃO: %d°", ret + 1);
    printf("\nCHAVE: %d", chave);
    printf("\nRESULTADO CHAVE: %d", v[ret]);

    return 0;
}