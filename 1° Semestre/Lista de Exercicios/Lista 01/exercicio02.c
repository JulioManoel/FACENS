/*
	Este programa calcula a media entre dois numeros
	22/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float x,y,media = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite um numero para ser calculado: ");
	scanf("%f",&x);
	printf("\nDigite outro numero para calcular a media entre os dois numeros: ");
	scanf("%f", &y);
	media = (x + y) / 2;
	printf("\nA media entre os dois numeros é de %.2f",media);
	return 0;
}
