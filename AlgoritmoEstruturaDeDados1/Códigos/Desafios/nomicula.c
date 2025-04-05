#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char nomeAluno[101], raAluno[101];
    while (scanf("%s %s", nomeAluno, raAluno) != EOF)
    {        
        int sizeNome = strlen(nomeAluno); 
        int sizeRa = strlen(raAluno);
        int sizeMenorString = sizeRa < sizeNome ? sizeRa : sizeNome;

        int sizeNomicula = sizeRa + sizeNome + 1;
        char* nomicula = (char*) malloc(sizeNomicula * sizeof(char));

        int idCharNome = 0, idCharRa = 0;
        for (int i = 0; i < sizeNomicula; i++)
        {        
            int opcao = i % 2;
            bool nomeNaoFinalizado = (idCharNome < sizeNome), raNaoFinalizado = (idCharRa < sizeRa);
            if ((opcao == 0 && nomeNaoFinalizado) || (opcao == 1 && !raNaoFinalizado))
            {
                nomicula[i] = nomeAluno[idCharNome];
                idCharNome++;
            }

            if ((opcao == 1 && raNaoFinalizado) || (opcao == 0 && !nomeNaoFinalizado)) 
            {
                nomicula[i] = raAluno[idCharRa];
                idCharRa++;
            } 
        }

        printf("%s\n", nomicula);
        free(nomicula);
    }
    return 0;
}