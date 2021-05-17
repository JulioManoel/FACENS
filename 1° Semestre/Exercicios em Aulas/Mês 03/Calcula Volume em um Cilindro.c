/*
	Este programa calcula o volume atraves da formula V=3,14*r2*h
	25/03/2021
*/

#include <stdio.h>

int main()
{
	float h, r = 0;
	printf("\nDigite a altura e o raio do cilindro: ");
	scanf("%f %f", &h, &r);
	printf("\nO volume desse cilindro %.2f", 3.14*(r*r)*h);
	return 0;
}
