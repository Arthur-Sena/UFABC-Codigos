//Lista 1 - Ex 2
#include <stdio.h>

int main(){

	printf("Digite um número:\n");
	
	int num;
	scanf("%d", &num);
	
	printf("Primos: \n");
	
	
	if (num >= 2)
		printf("2 \n");
	if (num >= 3)
		printf("3 \n");
	if (num >= 5)
		printf("5 \n");
			
	for (int i = 0; i <= num; i++) 
	{			
		if ( ((i % 2) != 0) &&
		     ((i % 3) != 0) &&
		     ((i % 5) != 0)
		 ){
			printf("%d \n", i);
		}
	}
	return 1;
}