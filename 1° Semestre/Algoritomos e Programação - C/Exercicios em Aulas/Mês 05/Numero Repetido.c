#include<stdio.h>
#include<stdlib.h>

int main()
{
	int numero[10], x, procurado,cont=0;
	for(x=0;x<10;x++)
	{
		printf("\nDigite o numero [%i]: ",x);
		scanf("%i", &numero[x]);
		fflush(stdin);
	}//for
	do
	{
		printf("\nDigite o numero que deseja procurar: ");
		scanf("%i", &procurado);
		fflush(stdin);
		for(x=0;x<10;x++)
			if(procurado == numero[x])
				cont++;
		if(cont==0)
		printf("\nNumero nao encontrado!");
	}while(cont==0);
	printf("\nNumero %i foi encontrado %i vez(es)\n\n",procurado,cont);
	system("pause");
	return 0;
}//main
