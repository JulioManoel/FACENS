/*
	Este programa calcula o salario de um funcionario
	22/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float salario, horasExtras, horasNormais = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite a quantidade de horas normais que o empregado trabalhou: ");
	scanf("%f", &horasNormais);
	printf("\nDigite a quandidade de horas extras que o empregado trabalhou: ");
	scanf("%f", &horasExtras);
	salario = (horasExtras * 15.00) + (horasNormais * 10.00);
	printf("\nO salário do empregado sera de %.2f", salario);
}
