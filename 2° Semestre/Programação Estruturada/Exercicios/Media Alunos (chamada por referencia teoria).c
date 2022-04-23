#include <stdio.h>
#include <stdlib.h>

void leitura(float *p,int *q);
void media(float *p1,float *p2,float *pm,int *q);

void main(){
	int qtde;
	float n1[10],n2[10],med[10];
	printf("\nCalcula a media\n");
	do{
		printf("\nQtde de qtde de alunos - max.10: ");
		scanf("%i", &qtde);
		fflush(stdin);
	}while(qtde<1 || qtde>10);
	printf("\nLeitura - nota 1: ");
	leitura(n1,&qtde);
	printf("\nLeitura - nota 2: ")
	leitura(n2,&qtde);
	media(n1,n2,med,qtde);
}

void leitura(float *p,int *q){
	int i;
	for(i=0;i<*q;i++,p++){
		do{
			printf("\nNota do %i aluno: ",i+1);
			scanf("%f",p);
			fflush(stdin);
		}while(*p<0 || *p>10);
	}
}

void media(float *p1,float *p2,float *pm,int *q){
	int i;
	for(i=0;i<*q;i++){
		*(pm+i)=(*(p1+i)+*(p2+i))/2;
	}
}
