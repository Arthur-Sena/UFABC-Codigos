//Lista 1 - Ex 6

#include <stdio.h>

int main(){

	printf("Digite um número:\n");
	
	int num, qnt, numAtual;
	scanf("%d", &num);
	

	qnt = 0;
	numAtual = 0;
	while (qnt <= num)
	{
	
	    if (numAtual == 2 || numAtual == 3 || numAtual == 5 || numAtual == 7)
	    {
	        qnt += 1;
	    	printf("%d \n", numAtual);
		}	
			    			
	    if ( ((numAtual % 2) != 0) &&
	         ((numAtual % 3) != 0) &&
	         ((numAtual % 5) != 0) &&
	         ((numAtual % 7) != 0) 
	     ){
	    	qnt += 1;
            printf("%d \n", numAtual);
        }
        numAtual += 1;		
	}
	return 1;
}
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