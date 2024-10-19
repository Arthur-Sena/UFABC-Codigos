//Lista 1 - Ex 8
#include <stdio.h>

int main(){
	printf("Digite um número:\n");
	
	int num, qnt;
	scanf("%d", &num);

	long fib[2];
    
	qnt = 5;
	
	fib[0] = 1;
	fib[1] = 2;
	fib[2] = 3;
	while (qnt <= num)
	{
	    long proximoNum = fib[1] + fib[2];

	    fib[0] = fib[1];
	    fib[1] = fib[2];
	    fib[2] = proximoNum;

        qnt += 1;		
	}
    
    printf("n-ésimo número: %ld", fib[2]);
	return 1;
}