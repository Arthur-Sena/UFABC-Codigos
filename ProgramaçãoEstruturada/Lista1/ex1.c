//Lista 1 - Ex 1

#include <stdio.h>

int main(){

	printf("Digite um número:\n");
	
	int num;
	scanf("%d", &num);
	
	for (int i = 0; i <= num; i++) 
	{
		if ( (i % 2) == 0){
			printf("%d \n", i);
		}
	}
	return 1;
}
