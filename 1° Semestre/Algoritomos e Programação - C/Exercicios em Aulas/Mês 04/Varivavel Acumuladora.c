#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	float num,soma = 0; //soma = acumuladora - inicializada com zero
	for(i=1;i<=5;i++)
	{
		printf("\nDigite %i numero: ",i);
		scanf("%f", &num);
		fflush(stdin);
		soma+= num;
	}//for
	printf("\nSoma = %.2f\n\n",soma);
	system("pause");
	return 0;
}//main
