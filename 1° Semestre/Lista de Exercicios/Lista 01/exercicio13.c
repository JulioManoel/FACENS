/*
	Este programa calcula o valor a ser pago para o encanador sendo que 8% é descontado do imposto de renda
	22/03/2021
*/

#include <stdio.h>

int main()
{
	int dias = 0;
	float valor = 0;
	printf("\nDigite a quantidade de dias trabalhados: ");
	scanf("%d", &dias);
	valor = dias * 35.00;
	valor = valor * 0.92 ;
	printf("\n o valor a ser pago para o encanador seria de %.2f", valor);
	return 0;
}
