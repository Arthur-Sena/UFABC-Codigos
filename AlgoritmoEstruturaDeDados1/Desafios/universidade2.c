//Arthur Sena
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOME_UNIVERSIDADE 50

int main()
{
	char *nomeUniversidade;
	int tempoMatricula;

    nomeUniversidade = (char *)malloc((MAX_NOME_UNIVERSIDADE +1) * sizeof(char));
    if (nomeUniversidade == NULL)
        return 1;
    
	printf("Onde voce estuda:");
    scanf("%50s", nomeUniversidade);

    printf("Quanto tempo:");
	scanf("%d", &tempoMatricula);

    printf("Voce estuda na %s ha %d anos.\n",nomeUniversidade, tempoMatricula);

	return 0;
}

