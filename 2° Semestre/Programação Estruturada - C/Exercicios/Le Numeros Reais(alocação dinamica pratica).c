#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(float **p);
void leitura(float *p);
void mostra(float *p);

void main(){
	float *ptr=NULL;
	setlocale(LC_ALL,"portuguese");
	aloca(&ptr);
	leitura(ptr);
	mostra(ptr);
}

void aloca(float **p){
	if((*p = (float*) realloc(*p,10*sizeof(float))) == NULL){
		printf("\nMemoria Insufisiente\n");
		exit(1);
	}
}

void leitura(float *p){
	int i;
	for(i=0;i<10;i++,p++){
		printf("\nDigite um número: ");
		scanf("%f",p);
	}
	p-=10;
}

void mostra(float *p){
	int i;
	for(i=0;i<10;i++,p++){
		printf("\nEndereço: %u - Número: %.2f",p,*p+30);
	}
}
