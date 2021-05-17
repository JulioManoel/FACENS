/*
	Este programa calcula o almento do salario em 5% ou 7%
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float salario = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite o seu salário: ");
	scanf("%f", &salario);
	if (salario >= 1000)
	{
		printf("\nO salário vai para %.2f", salario + (salario * 0.07));
	}
	else
	{
		printf("\nO salário vai para %.2f", salario + (salario * 0.05));
	}
	return 0;
}
