#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>//biblilioca do toupper
#include<math.h>//biblioteca do pow

int main()
{
	char op = 's';
	float lado,p,a;
	while(toupper(op) == 'S') //bibliotaca ctype.h
	{
		system("cls"); //limpa a tela
		printf("\nDigite o lado de um quadrado: ");
		scanf("%f", &lado);
		fflush(stdin);
		a=pow(lado, 2); //bilioteca math.h
		p=4*lado;
		printf("\nArea: %.2f\nPerimetro: %.2f\n",a,p);
		printf("\nDeseja continuar? [S] Sim ou [N] Nao: ");
		op=getche();
		fflush(stdin);
	}//while
	
	system("pause");
	return 0;
}//main
