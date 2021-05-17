/*
	Este programa verifica se o ano é bissexto ou não
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
		printf("\nO ano é bissexto");
	}
	else
	{
		printf("\nO ano não é bissexto");
	}
	return 0;
}
