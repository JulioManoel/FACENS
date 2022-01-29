#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aloca(float **p,int tam);
void leitura(float *p,int tam);
void maior_temp(float *p,int tam,float *pm,int *pd);

void main(){
	char op;
	int cont=0,dia;
	float *ptr=NULL,maior;
	setlocale(LC_ALL,"portuguese");
	printf("\nRecebe as temperaturas e mostra a maior e o dia em que ocorreu");
	do{
		aloca(&ptr,cont+1);
		leitura(ptr,cont);
		maior_temp(ptr,cont,&maior,&dia);
		printf("\nMaior temperatura = %.2f - dia: %i",maior,dia);
		cont++;
		printf("\nDeseja continuar <S/N>: ");
		op = getch();
		fflush(stdin);
	}while(op !='n' || op !='N');
}

void aloca(float **p,int tam){
	if((*p=(float*)realloc(*p,tam*sizeof(float))) == NULL){
		exit(1);
	}	
}

void leitura(float *p,int tam){
	printf("\nNumero: ");
	scanf("%f",p+tam);
}

void maior_temp(float *p,int tam,float *pm,int *pd){
	if(tam==0){
		*pm=*p;
		*pd=tam+1;
	}
	else if(*(p+tam) >*pm){
		*pm=*(p+tam);
		*pd=tam+1;		
	}
}
