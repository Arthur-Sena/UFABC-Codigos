#include <stdio.h>

int somaDivisores(int n)
{
    int soma = 0;
    int max = n / 2 + 1;
    
    for (int i = 1; i < max; i++)
        if (n % i == 0)
            soma += i;

    return soma;
}

char *conceito(int n)
{
    int soma = somaDivisores(n);
    if (soma == n)
        return "perfeito";
    if (soma < n)
        return "deficiente";
    if (soma > n)
        return "abundante";
}

int main()
{
    int N = 0;
    while (scanf("%d", &N) && N != -1)
        printf("%s\n", conceito(N));

    return 0;
}