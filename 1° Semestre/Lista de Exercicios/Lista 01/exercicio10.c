/*
	Calcula o consumo meido de combustivel
	22/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float distancia, combustivel, consumo = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite a distância do percurso(km): ");
	scanf("%f", &distancia);
	printf("\nDigite o total de combustivel gasto(l): ");
	scanf("%f", &combustivel);
	consumo = distancia / combustivel;
	printf("\nO consumo médio de combustivel foi de %.2f", consumo);
	return 0;
}
