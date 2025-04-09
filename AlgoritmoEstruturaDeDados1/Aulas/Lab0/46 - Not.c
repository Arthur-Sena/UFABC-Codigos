#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool string2bool(char *str) {
    return (strcmp(str, "true") == 0) ? true : false;
}

int main() {
    char P[6];
    bool p_bool;

    scanf("%s", P);

    p_bool = string2bool(P);

    printf("%s\n", !(p_bool) ? "true" : "false");

    return 0;
}