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
	printf("\nDigite tr�s medidas para o tri�ngulo sendo a maior a ultima: ");
	scanf("%d %d %d",&l1,&l2,&l3);
	if ((l1 + l2) > l3)
	{
		if (l1 == l2 && l2 == l3)
			{	
				printf("\nO tri�ngulo � Equil�tero\n");
			}
			
		else
		{ 
			if (l1 == l2 || l2 == l3 || l1 == l3)
			{
			printf("\nO tri�ngulo � Is�sceles\n");
			}
			if (l1 != l2 && l1 != l3)
			{
				printf("\nO tri�ngulo � Escaleno\n");
			}
		}
	}
	else
	{
		printf("\nN�o � um tri�ngulo\n");
	}
	system("pause");
	return 0;
}
