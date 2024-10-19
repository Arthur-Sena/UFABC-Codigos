//Lista 1 - Ex 3

#include <stdio.h>

int main(){

	int n, mtf = 1;
	printf("Digite um numero Natural:");
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		mtf = mtf*i;
	}
	
	printf("%d! (fatorial de %d): %d\n", n, n, mtf);

	return 0;
}
