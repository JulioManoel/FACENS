/*
	Este programa classifica um tringulo pela medida dos seus lados
	29/03/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int l1,l2,l3 = 0;
	setlocale(LC_ALL,"portuguese");
	printf("\nDigite três medidas para o triângulo sendo a maior a ultima: ");
	scanf("%d %d %d",&l1,&l2,&l3);
	if ((l1 + l2) > l3)
	{
		if (l1 == l2 && l2 == l3)
			{	
				printf("\nO triângulo é Equilátero\n");
			}
			
		else
		{ 
			if (l1 == l2 || l2 == l3 || l1 == l3)
			{
			printf("\nO triângulo é Isósceles\n");
			}
			if (l1 != l2 && l1 != l3)
			{
				printf("\nO triângulo é Escaleno\n");
			}
		}
	}
	else
	{
		printf("\nNão é um triângulo\n");
	}
	system("pause");
	return 0;
}
