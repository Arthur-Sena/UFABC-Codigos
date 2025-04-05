#include <stdio.h>

int main(){
    double num;
    
    scanf("%lf", &num);
    int parte_inteira = (int)num;
    
    printf("%d.0000\n", parte_inteira);
    return 0;
}