/*
	Este programa verifica se � negativo ou n�o
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
		printf("\nO n�mero � positivo");
	}
	else
	{
		printf("\nO n�mero � negativo");
	}
	return 0;
}
