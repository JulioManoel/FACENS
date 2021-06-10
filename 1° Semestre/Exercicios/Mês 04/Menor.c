#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	float num,menor; //menor = variavel auxiliar
	for(i=0;i<=4;i++)
	{
		printf("\nDigite o %d numero: ",i+1);
		scanf("%f",&num);
		if(i==0 || num<menor) //é a primeira vez ou menor?
		{
			menor=num;
		}
	}
	printf("\nO menor numero digitado = %.2f",menor);
	system("pause");
	return 0;
}
