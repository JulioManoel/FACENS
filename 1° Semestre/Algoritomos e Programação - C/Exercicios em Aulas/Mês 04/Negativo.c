#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	float num;
	for(i=1;i<4;i++)
	{
		printf("\nDigite um numero: ");
		scanf("%f", &num);
		fflush(stdin);
		if(num<0)
		{
			printf("\nO numero %.2f \x82 negativo\n\n",num);
		}
		else
		{
			printf("\nO numero %.2f nao \x82 negativo",num);
		}
	}//for
	system("pause");
	return 0;
}//main
