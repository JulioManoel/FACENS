/*
	Este programa calcula a circuferencia de um circulo
	22/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float c,r = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite o raio de um circulo: ");
	scanf("%f", &r);
	c = 2 * 3.14 * r;
	printf("\nO valor da circuferência do circulo é de %.2f", c);
	return 0;
}
