#include<stdio.h>
#include<stdlib.h>

int main()
{
	int op;
	float saldo,valor;
	printf("\nBanco FACENS\n\n");
	printf("\nSaldo inicial (reais): ");
	scanf("%f",&saldo);
	fflush(stdin);
	do{
		system("cls");
		printf("\nMenu:\n\n[1]Depositar\n[2]Retirar\n[3]Sair\n\nOpcao: ");
		op = getche();
		if(op==1 || op==2)
		{
			printf("\nDigite o valor (reais): ");
			scanf("%f",&valor);
			fflush(stdin);
		}//if
		switch (op)
		{
			case 1:
				saldo+=valor; //saldo = saldo + valor
				printf("\nSaldo atual = %.2f\n",saldo);
				break;
			case 2:
				saldo-=valor; //saldo = saldo - valor
				printf("\nSaldo atual = %.2f\n",saldo);
				break;
			case 3:
				printf("\nMuito Obrigado, por usar nosso banco\n");
				break;
			default:
				printf("\nOpcao invalida\n");
		}
		system("pause");
	}while(op!=3);
	if(saldo == 0)
		printf("\nConta zerada\n");
	else if(saldo<0)
		printf("\nConta estourada\n");
	else
		printf("Conta preferencial\n");
	system("pause");
	return 0;
}
