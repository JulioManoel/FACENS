/*
	Este programa ver se � positivo e mostra se � par ou impar
	29/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int num1 = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite um n�mero inteiro: ");
	scanf("%d", &num1);
	if (num1 > 0)
	{
		if (num1 % 2)
		{
			printf("\nO n�mero � par\n");
		}
		else
		{
			printf("\nO n�mero � impar\n");
		}
	}
	else
	{
		printf("\nO n�mero digitado � negativo ou nulo\n");
	}
	system("pause");
	return 0;
}
