/*
	Este programa verifica se é negativo ou não
	23/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	float n = 0;
	printf("\nDigite um numero: ");
	scanf("%f", &n);
	if (n>0)
	{
		printf("\nO número é positivo");
	}
	else
	{
		printf("\nO número é negativo");
	}
	return 0;
}
