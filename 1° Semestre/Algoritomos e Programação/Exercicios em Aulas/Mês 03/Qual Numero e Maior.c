/*
	Este programa verifica qual n�mero � maior
	29/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int num1, num2 = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nO digite dois n�meros: ");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
	{
		printf("\nO n�mero %d � maior que %d\n", num1,num2);
	}
	else if (num2 > num1)
	{
		printf("\nO n�mero %d � maior que %d\n", num2,num1);
	}
	else
	{
		printf("\nOs n�meros s�o iguais\n");
	}
	system("pause");
	return 0;
}
