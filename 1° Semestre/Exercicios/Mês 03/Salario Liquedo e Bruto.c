/*
	Este progrma calcula o salario liquedo e bruto do empregado que trabalhou 62 horas
	23/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int refeicao = 0;
	float valorH, salBruto, salLi = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nQual seria o valor pago por hora: ");
	scanf("%f", &valorH);
	printf("\nQuantas refei��es o empregado faz em 62 horas: ");
	scanf("%d", &refeicao);
	salBruto = (40 * valorH) + (22 * (valorH * 3));
	salLi = salBruto - (1.5 * refeicao);
	printf("\nO sal�rio bruto � de R$%.2f e o sal�rio l�quido � de R$%.2f\n\n", salBruto, salLi);
	system("pause");	
	return 0;
}
