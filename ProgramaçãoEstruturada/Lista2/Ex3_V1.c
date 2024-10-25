#include <stdio.h>

void ordena(int valores[], int n)
{
    for (int l = 0; l < n; l++)
        for (int j = 0; j < n; j++)
        {
            int cm = 0;
            if (valores[j] != 0)
            {
                for (int k = 0; k < n; k++)
                    if (valores[k] != 0)
                    {
                        if (valores[j] > valores[k])
                        {
                            cm = 0;
                            break;
                        }
                        else
                        {
                            cm = 1;
                        }
                    }

                if (cm == 1)
                {
                    printf("%d, ", valores[j]);
                    valores[j] = 0;
                }
            }
        }
}

int main()
{
    int valores[1000];
    int n;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nDigite o %dº valor da lista (entre 1 e 100): ", i + 1);
        scanf("%d", &valores[i]);
    }

    ordena(valores, n);

    return 0;
}