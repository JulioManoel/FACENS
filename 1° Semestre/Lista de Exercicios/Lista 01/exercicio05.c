/*
	Este programa pega dois valores e calcula a divis�o e o resto da divis�o
	22/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	int x,y,r,d = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite um numero inteiro: ");
	scanf("%d", &x);
	printf("\nDigite outro numero inteiro: ");
	scanf("%d", &y);
	d = x / y;
	r = x % y;
	printf("\nO valor dividido � %d e o resto da diviz�o � %d", d, r);
	return 0;
}
