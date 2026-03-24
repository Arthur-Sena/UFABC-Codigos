#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool string2bool(char *str) {
    return (strcmp(str, "true") == 0) ? true : false;
}

char* bool2string(bool b) {
    return b ? "true" : "false";
}

int main() {
    char P[6], Q[6];
    bool p_bool, q_bool;
    bool soma, vaiUm;

    scanf("%s %s", P, Q);

    p_bool = string2bool(P);
    q_bool = string2bool(Q);

    soma = p_bool != q_bool;
    vaiUm = p_bool && q_bool;

    printf("%s %s\n", 
        bool2string(vaiUm), 
        bool2string(soma)
    );

    return 0;
}