/*
	Este programa mostra dois numeros em ordem cresente
	24/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float x, y = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite dois números para que seja mostrado em ordem cresente: ");
	scanf("%f %f", &x, &y);
	if (x > y)
	{
		printf("\n%.2f e %.2f", y, x);
	}
	if (x < y)
	{
		printf("\n%.2f e %.2f", x, y);
	}
}
