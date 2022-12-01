#include <stdio.h>
#include <stdlib.h>

struct cliente{
	char nome[30];
	int conta;
	float saldo;
};

struct cliente cadastro();
struct cliente movimento(struct cliente x,int op);

void main(){
	struct cliente cli[10];
	int op,cont=0, num_conta,i,achou;
	
	do{
		system("cls");
		printf("[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Fim\n");
		scanf("%i",&op);
		fflush(stdin);
		switch(op){
			case 1:
				if(cont<10){
					cli[cont]=cadastro();
					cont++;
				}
				else{
					printf("\nCadastro Lotado.\n\n");
					system("PAUSE");
				}
				break;
			case 2:
				break;
			case 3:
				printf("\nConta:");
				scanf("%i",&num_conta);
				for(i=0;i<cont;i++){
					if(cli[i].conta==num_conta){
						cli[i]=movimento(cli[i],op);
						achou=1;
					}
				}
				if(achou==0){
					printf("\nConta invalida");
				}
				break;
		}
	}while(op!=4);
}

struct cliente cadastro(){
	struct cliente aux;
	static int n_conta=1000;
	
	printf("\nNome:");
	gets(aux.nome);
	fflush(stdin);
	aux.conta=n_conta;
	aux.saldo=0;
	printf("\nConta: %i\n\n",n_conta);
	n_conta++;
	system("PAUSE");
	return aux;
}

struct cliente movimento(struct cliente x,int op){
	float valor;
	
	printf("\nNome: %s\nSaldo: %.2f\n\n",x.nome,x.saldo);
	printf("\nDigite o valor a ser retirado/depositado: ");
	scanf("%f",&valor);
	fflush(stdin);
	if(op==2){
		x.saldo+=valor;
	}
	else{
		if(valor<=x.saldo){
			x.saldo-=valor;
		}
		else{
			printf("\nSaldo insulfisiente\n\n");
			system("PAUSE");
		}
	}
	printf("\nSaldo atualizado: %.2f",x.saldo);
	system("PAUSE");
	return x;
}
