/*
	Este programa verifica se o ano � bissexto ou n�o
	24/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	int ano = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite um ano: ");
	scanf("%d", &ano);
	if ((ano%4) == 0)
	{
		printf("\nO ano � bissexto");
	}
	else
	{
		printf("\nO ano n�o � bissexto");
	}
	return 0;
}
