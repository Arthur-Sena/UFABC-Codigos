#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char *text;
    text = (char*) malloc(20001 * sizeof(char));
    scanf("%s", text);

    int sizeSubChar1, sizeSubChar2;
    scanf("%d %d", &sizeSubChar1, &sizeSubChar2);

    int sizeStringIntercalada = strlen(text);
    char *stringIntercalada = (char*) malloc((sizeStringIntercalada + 1) * sizeof(char));

    int idAtual = 0, idSubChar1 = 0, idSubChar2 = sizeSubChar1;
    while (idAtual < sizeStringIntercalada) {
        if (idSubChar1 < sizeSubChar1 && (idSubChar2 >= sizeStringIntercalada || text[idSubChar1] <= text[idSubChar2])) {
            stringIntercalada[idAtual] = text[idSubChar1];
            idSubChar1++;
        }
        else if (idSubChar2 < sizeStringIntercalada) {
            stringIntercalada[idAtual] = text[idSubChar2];
            idSubChar2++;
        }
        idAtual++;
    }
    stringIntercalada[idAtual] = '\0';

    printf("%s\n", stringIntercalada);

    free(text);
    free(stringIntercalada);

    return 0;
}