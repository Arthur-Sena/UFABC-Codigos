#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    while (B > 0) {
        A--;
        B--;
    }
    
    printf("%d\n", A);

    return 0;
}