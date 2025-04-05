//Arthur Sena
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *universidade;
    int anos;

    universidade = (char *)malloc(51 * sizeof(char));
    if (universidade == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    scanf("%50s %d", universidade, &anos);
    printf("Voce estuda na %s ha %d anos.\n", universidade, anos);

    free(universidade);

    return 0;
}