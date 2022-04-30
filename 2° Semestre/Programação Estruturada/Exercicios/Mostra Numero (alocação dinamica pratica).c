#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(int **p,int tam);	
void leitura(int *p);
void mostra(int *p,int tam);

void main(){
	char op;
	int *ptr=NULL,cont=0;
	setlocale(LC_ALL,"portuguese");
	do{
		aloca(&ptr,cont+1);
		leitura(ptr+cont);
		cont++;
		printf("\nDeseja continuar <S/N>: ");
		op = getch();
		fflush(stdin);
	}while(op !='n' && op!='N');
	mostra(ptr,cont);
}

void aloca(int **p,int tam){
	if((*p = (int*) realloc(*p,tam*sizeof(int))) == NULL){
		printf("Erro na alocação");
		exit(1);
	}
	printf("\nFunção Alocação %u",*p);
}

void leitura(int *p){
	printf("\nEndereco: %u - Numero: ",p);
	scanf("%i",p);
	fflush(stdin);
}

void mostra(int *p,int tam){
	int i;
	for(i=0;i<tam;i++,p++){
		printf("\nEndereço: %u - Numero: %i\n",p,*p);
	}
}
