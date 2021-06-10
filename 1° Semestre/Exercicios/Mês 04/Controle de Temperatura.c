/*
Este programa diz se esta friu
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i;
	float temp;
	for (i = 1; i <= 5; i++)
	{
		printf("\n%d a temperatura em Fahrenheit: ", 1);
		scanf("%f", &temp);
		temp = (temp - 32) / 1.8;
		if (temp < 15)
		{
			printf("\nFrio\n");
		}
		else if (temp > 30)
		{
			printf("Quente");
		}
		else
		{
			printf("Normal");
		}
		system("pause");
	}
}
