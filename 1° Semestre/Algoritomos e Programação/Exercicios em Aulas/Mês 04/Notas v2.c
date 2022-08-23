#include<stdio.h>
#include<stdlib.h>

int main()
{
	char op;
	float n1,n2;
	do{
		system("cls");//limpar tela
		printf("\nCalcula a media de notas dos alunos\n");
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
		printf("\nDeseja calcular a media para outro aluno? [S] Sim ou [N] Nao: ");
		op = getche();
	}while(op!='n' || op!='N');
	system("pause");
	return 0;
}
