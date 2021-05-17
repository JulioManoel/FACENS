/*
	Este programa calcula a area de um triangulo
	22/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float base, altura, area= 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite o valor da base do triângulo: ");
	scanf("%f", &base);
	printf("\nDigite o valor da altura do triângulo: ");
	scanf("%f", &altura);
	area = (base*altura) / 2;
	printf("\nA área do triângulo é de %.2f", area);
	return 0 ;
}
