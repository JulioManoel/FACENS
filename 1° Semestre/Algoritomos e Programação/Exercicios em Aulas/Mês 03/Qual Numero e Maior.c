/*
	Este programa verifica qual número é maior
	29/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int num1, num2 = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nO digite dois números: ");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
	{
		printf("\nO número %d é maior que %d\n", num1,num2);
	}
	else if (num2 > num1)
	{
		printf("\nO número %d é maior que %d\n", num2,num1);
	}
	else
	{
		printf("\nOs números são iguais\n");
	}
	system("pause");
	return 0;
}
