#include <stdio.h>

char* mesCorrespondente(int M) {
    switch (M) {
        case 1:  return "JANEIRO";
        case 2:  return "FEVEREIRO";
        case 3:  return "MARCO";
        case 4:  return "ABRIL";
        case 5:  return "MAIO";
        case 6:  return "JUNHO";
        case 7:  return "JULHO";
        case 8:  return "AGOSTO";
        case 9:  return "SETEMBRO";
        case 10: return "OUTUBRO";
        case 11: return "NOVEMBRO";
        case 12: return "DEZEMBRO";
        default: return "MES INVALIDO";
    }
}

int main () {
    int M;

    scanf("%d", &M);

    printf("%s\n", mesCorrespondente(M));

    return 0;
}