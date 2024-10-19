// Arthur Sena
// Conversor de Temperatura - Ex 5 Lista 1
#include <stdio.h>

float toCelsius (double tempF) {
	float tempC = ((tempF - 32) / 9) * 5;
	return tempC;
}

float toFahrenheit (double tempC) {
	float tempF = ((tempC / 5) * 9) + 32;
	return tempF;
}


int main(){

	printf("Unidade de medida: \n 1: Celsius \n 2: Fahrenheit \n");

	int opcao;
	scanf("%d", &opcao);

	printf("Temperatura atual: ");
	float temperatura;
	scanf("%f", &temperatura);
	
	
	float tempConvertida;
	if (opcao == 1){
		tempConvertida = toFahrenheit(temperatura);
	}
	else {
		tempConvertida = toCelsius(temperatura);
	}
	
	printf("Temperatura convertida: %f", tempConvertida);
	return 0;
}