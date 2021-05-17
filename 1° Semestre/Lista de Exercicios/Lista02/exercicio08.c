/*
	Este programa calcula o valor da conta de um plano de 50 reais e 1,50 a mais por minuto
	24/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main ()
{
	float minutos = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite quantos minutos a mais você utilizo do seu plano: ");
	scanf("%f", &minutos);
	printf("O valor da fatura sera de %.2f", 50+(minutos * 1.5));
	return 0;
}
