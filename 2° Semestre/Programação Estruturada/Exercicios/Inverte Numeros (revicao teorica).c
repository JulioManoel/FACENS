#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(int **p,int tam);
void leitura(int *p);
void imprime_invertido(int *p,int tam);

void main(){
	char op;
	int *ptr=NULL,cont=0;
	setlocale(LC_ALL, "portuguese");
	printf("\nRecebe valores e imprime invertido");
	do{
		aloca(&ptr,cont+1);
		leitura(ptr+cont);
		cont++;
		printf("\nDeseja continuar <S/N>: ");
		op = getch();
	}while(op != 'n' || op != 'N');
	imprime_invertido(ptr,tam);
}

void aloca(int **p,int tam){
	if((*p = (int*)realloc(*p,tam*sizeof(int))) == NULL){
		exit(1);
	}
}

void leitura(int *p){
	printf("\nEndereço: %u - Numero: ",p);
	scanf("%i",p);
}

void imprime_invertido(int *p,int tam){
	int i;
	p-=tam-1;
	for(i=0;i<tam;i++,p--){
		printf("\nEndereço: %u - Numero: %i",p,*p);
	}
}
