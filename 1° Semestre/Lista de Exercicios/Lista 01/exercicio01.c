/*
	Programa para fazer o numero Dobrar
	22/03/2021
*/

#include <stdio.h>

int main()
{
	float x = 0;
	printf("\nDigite um numero para que seja dobrado: ");
	scanf("%f", &x);
	x = x * 2;
	printf("\nO dobro do valor digitado é %f",x);
	return 0;
}
