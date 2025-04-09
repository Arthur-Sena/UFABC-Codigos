#include <stdio.h>
#include <ctype.h>

char vogais[5] = {'a', 'e', 'i', 'o', 'u'};

int ehVogal(char letra) {
    for (int i = 0; i < 5; i++) {
        if (letra == vogais[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char letra;

    scanf("%c", &letra);

    letra = tolower(letra);

    if (ehVogal(letra)) 
    {
        printf("vogal\n");
    } else {
        printf("consoante\n");
    }

    return 0;
}