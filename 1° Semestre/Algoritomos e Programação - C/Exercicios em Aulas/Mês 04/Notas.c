#include<stdio.h>
#include<stdlib.h>

int main()
{
	float n1,n2;
	do{
		printf("\nDigite a nota 1 (0~10): ");
		scanf("%f",&n1);
		fflush(stdin);
		if(n1<0 || n1>10)
			printf("\nValor invalido\n\n");
	}while(n1<0 || n1>10);
		do{
		printf("\nDigite a nota 2 (0~10): ");
		scanf("%f",&n2);
		fflush(stdin);
		if(n2<0 || n2>10)
			printf("\nValor invalido\n\n");
	}while(n2<0 || n2>10);
	printf("\nMedia = %.2f\n\n", (n1+n2)/2);
	system("pause");
	return 0;
}
