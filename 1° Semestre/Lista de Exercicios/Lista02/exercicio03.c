/*
	Este programa faz divição
	23/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	int n, c, d = 0;
	printf("\nDigite dois números o numerador e denominador para realizar uma divição: ");
	scanf("%f %f", &n, &d);
	c = n / d;
	if (c >= 0)
	{
		if(d != 0)
		{
		printf("\nO resultado da conta é %.2f", c);
		}
	}
	else
	{
		printf("\nNão existe divisão por zero");
	}
	return 0;
}
