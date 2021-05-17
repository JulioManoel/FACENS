/*
	Este programa converte de Fahrenheit para Celsius
	22/03/2021
*/

#include <stdio.h>

int main()
{
	float f,c = 0;
	printf("\nDigite uma temperatura em Fahrenheit para que seja convertida para Celsius: ");
	scanf("%f", &f);
	c = (f - 32) / 1.8;
	printf("\nA temperatura em Celsius é de %.2f", c);
	return 0;
}
