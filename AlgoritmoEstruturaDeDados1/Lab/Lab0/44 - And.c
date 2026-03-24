#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool string2bool(char *str) {
    return (strcmp(str, "true") == 0) ? true : false;
}

int main() {
    char P[6], Q[6];
    bool p_bool, q_bool;

    scanf("%s %s", P, Q);

    p_bool = string2bool(P);
    q_bool = string2bool(Q);

    printf("%s\n", (p_bool && q_bool) ? "true" : "false");

    return 0;
}