/*
	Este programa converte metros em centimetros
	22/03/2021
*/

#include <stdio.h>

int main()
{
	float m,c = 0;
	printf("\nDigite um valor em metros para que possa ser convertido para centimetros: ");
	scanf("%f",m);
	c = m * 100;
	printf("\nO valor em centimetros é de aprocimadamente %.2f",c);
	return 0;
}
