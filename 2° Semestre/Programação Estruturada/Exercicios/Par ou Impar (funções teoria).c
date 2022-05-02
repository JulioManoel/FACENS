#include <stdio.h>
#include <stdlib.h>

int par(int n); //Protótipo

void main(){
	int num, verifica;
	printf("\nDigite um numero: ");
	scanf("%i", &num);
	fflush(stdin);
	verifica = par(num); //Chamada da Função
	if(verifica==1){
		printf("\nO numero %1 \x82 par\n\n",num);
	}
	else{
		printf("\nO numero %i NAO \x82 par",num);
		system("pause");
	}
}

int par(int n){
	if(n%2 == 0){
		return 1; //par
	}
	else{
		return 0; //impar
	}
}
