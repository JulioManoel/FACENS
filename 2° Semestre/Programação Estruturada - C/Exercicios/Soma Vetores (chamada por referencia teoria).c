#include <stdio.h>
#include <stdlib.h>

void leitura(float *p, int *q);
void resultante(float *pa,float *pb,float *pc,int *q);

void main(){
	int qtde;
	float a[10],b[10],c[10];
	printf("\nSoma 2 vetores\n");
	do{
		printf("\nQtde de elementos - max.10: ");
		scanf("%i",&qtde);
		fflush(stdin);
	}while(qtde<1 || qtde>10);
	printf("\nLeitura - vetor a: ");
	leitura(a, &qtde);
	printf("\nLeitura - vetor b: ");
	leitura(b, &qtde);
	printf("\nResultande - Vetor C:\n");
	resultante(a,b,c,&qtde);
}

void leitura(float *p,int *q){
	int i;
	for(i=0;i<*q;i++,p++){
		printf("\nvet[%i] = ",i+1);
		scanf("%f", p);
		fflush(stdin);
	}
}

void resultante(float *pa,float *pb,float *pc,int *q){
	int i;
	for(i=0;i<*q;i++,pa++,pb++,pc++){
		*pc = *pa + *pb;
		printf("\nVet[%i] = %.2f",i+1,*pc);
	}
}
