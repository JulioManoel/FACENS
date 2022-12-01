#include<stdio.h>
#include<stdlib.h>

int main()
{
	int numero[12], x, neg=0;
	for(x=0;x<12;x++)
	{
		printf("Digite o numero da posicao %i: ",x);
		scanf("%i", &numero[x]);
		fflush(stdin);
	}//for
	for(x=0;x<12;x++)
		if(numero[x]<0)
			neg++;
	printf("\nQuantidade de numeros negativos = %i\n\n",neg);
	system("pause");
	return 0;
}//main
