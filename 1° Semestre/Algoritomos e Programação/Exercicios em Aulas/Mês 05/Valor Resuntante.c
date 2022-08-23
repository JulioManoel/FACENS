#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[100], B[100], C[100],i,qtde;
	do{
		printf("\nDigite a quantidade de elementosd o vetor(max.100): ");
		scanf("%i", &qtde);
		fflush(stdin);
	}while(qtde<1 || qtde>100);
	printf("\nDigite os valores de A:");
	for(i=0; i<qtde;i++)
	{
		printf("\nDigite A[%i]= ",i);
		scanf("%i", &A[i]);
		fflush(stdin);
	}//for A
	printf("\nDigite os valores de B:");
	for(i=0; i<qtde;i++)
	{
		printf("\nDigite B[%i]= ",i);
		scanf("%i", &B[i]);
		fflush(stdin);
	}//for B
	printf("\nO vetor resultante C:\n");
	for(i=0; i<qtde;i++)
	{
		C[i]=A[i]+B[i];
		printf("\nC[%i] = %i\n\n",i,C[i]);
	}//for C
	system("pause");
	return 0;
}
