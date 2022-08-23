/*
	Este programa ver se é positivo e mostra se é par ou impar
	29/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int num1 = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite um número inteiro: ");
	scanf("%d", &num1);
	if (num1 > 0)
	{
		if (num1 % 2)
		{
			printf("\nO número é par\n");
		}
		else
		{
			printf("\nO número é impar\n");
		}
	}
	else
	{
		printf("\nO número digitado é negativo ou nulo\n");
	}
	system("pause");
	return 0;
}
