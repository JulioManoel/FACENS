/*
	Este programa verifica se um numero esta na faixa de 0 a 9
	23/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float n = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite um numero: ");
	scanf("%f", &n);
	if (9<n>0)
	{
		printf("\nO n�mero esta na faixa de 0 a 9");
	}
	else 
	{
		printf("\nO n�mero n�o esta na faixa de 0 a 9");
	}
	return 0;
}
