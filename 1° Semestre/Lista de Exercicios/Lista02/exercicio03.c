/*
	Este programa faz divi��o
	23/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	int n, c, d = 0;
	printf("\nDigite dois n�meros o numerador e denominador para realizar uma divi��o: ");
	scanf("%f %f", &n, &d);
	c = n / d;
	if (c >= 0)
	{
		if(d != 0)
		{
		printf("\nO resultado da conta � %.2f", c);
		}
	}
	else
	{
		printf("\nN�o existe divis�o por zero");
	}
	return 0;
}
