#include <stdio.h>
#include <stdlib.h>

void aloca(int **p,int tam);
void leitura(int *p,int tam);
void imprime_invertido(int *p,int tam);

void main(){
	int *ptr=NULL, qtde;
	printf("\nRecebe valores e imprime invertido");
	printf("\nQtos numeros: ");
	scanf("%i",&qtde);
	fflush(stdin);
	aloca(&ptr,qtde);
	leitura(ptr,qtde);
	imprime_invertido(ptr,qtde);	
}

void aloca(int **p,int tam){
	if((*p = (int*)realloc(*p,tam*sizeof(int)))== NULL){
		exit(1);
	}
}//aloca

void leitura(int *p, int tam){
	int i;
	for(i=0;i<tam;i++,p++){
		printf("\nEndereco: %u - numero: ",p);
		scanf("%i",p);
		fflush(stdin);
	}
}

void imprime_invertido(int *p,int tam){
	int i;
	p=p+tam-1;
	for(i=0;i<tam;i++,p--){
		printf("\nEndereco: %u - numero: %i",p,*p);
	}
}
