/*
	Este programa recebe dois numeros e mostra o maior
	24/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float x,y = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite dois numeros para que possamos mostrar o maior: ");
	scanf("%f %f", &x, &y);
	if (x > y)
	{
		printf("\n%.2f é maior que %.2f", x, y);
	}
	else if(x == y)
	{
		printf("\n%.2f e %.2f são iguais");
	}
	else
	{
		printf("\n%.2f é maior que %.2f", y, x);
	}
	return 0;
}
