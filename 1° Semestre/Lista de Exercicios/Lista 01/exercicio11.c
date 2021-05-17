/*
	Este programa calcula a velocidade media
	22/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float v, d, t = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite a distância do percurso(km): ");
	scanf("%f", &d);
	printf("\nDigite o tempo para percorrer o percurso(h): ");
	scanf("%f", &t);
	v = d / t;
	printf("\nA velocidade média é de %.2f", v);
	return 0;
}
