#include<stdio.h>
#include<stdlib.h>

int main()
{
	int chance = 3, acertou = 0;
	unsigned char a, b;
	do{
		srand(time(NULL));
		system("cls");
		printf("\nJogo do Adivinha");
		printf("\nChances: %d\t Acertou: %d",chance,acertou);
		a = 1+(rand() %10);
		printf("\n\nDigite qual e o numero de 1 a 10 de %c: ", a);
		scanf("%c", &b);
		if(b == a){
			acertou++;
			printf("\nAcertou\n\n");
		}
		else{
			chance--;
			printf("\nErrou\n\n");
		}
		system("pause");
	}while(chance!=0);
	printf("\n\nAcabou as chances\n");
	Beep(100, 1500);
	system("pause");
	return 0;
}
