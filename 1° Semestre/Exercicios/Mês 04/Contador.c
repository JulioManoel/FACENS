#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,num,cont = 0; //cont = contadora foi inicializada com 0
	for(i=0;i<=4;i++)
	{
		printf("\nDigite o %d numero: ",i+1);
		scanf("%d",&num);
		fflush(stdin);
		if(num%2 == 0) //num é par - se o resto da divição for 0
		{
			cont++
		}
	}//for
	printf("\nQuantidade de numeros pares = %d\n",num);
	system("pause");
	return 0;
}//main
