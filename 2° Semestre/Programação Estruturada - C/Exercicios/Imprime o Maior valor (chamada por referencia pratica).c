#include<stdio.h>
#include<stdlib.h>

void leitor(float *p, int qtde);
int buscaMaior(float *pm,int qtde);
void imprime(float *p,int pos);

void main(){
	int qtde,pos;
	float vet[10],*pv;
	do{
		printf("\nQtde de elementos - max.10");
		scanf("%i", &qtde);
	}while(qtde<=0 || qtde>=10);
	leitor(pv, qtde);
	pos = buscaMaior(pv, qtde);
	imprime(pv, pos);
}

void leitor(float *p, int qtde){
	int i;
	for(i=0;i<=qtde;i++,p++){
		printf("\nvet[%i] = ",i+1);
		scanf("%f",p);
		fflush(stdin);
	}
}

int buscaMaior(float *p,int qtde){
	int i,pos=0; //posição do primeiro elemento
	float maior=*p; //conteudo do primeiro elemento
	p++; //aponta para o segundo elemento
	for(i=1;i<qtde;i++,p++){
		if(maior<*p){
			maior=*p;
			pos++;
		}
	}
	return pos;
}

void imprime(float *p,int pos){
	printf("\nO maior valor = %.2f - posicao %i \n\n",*(p+pos),pos);
	system("pause");
}
