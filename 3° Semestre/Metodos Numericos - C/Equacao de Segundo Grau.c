#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Funções
void recebeParametros(float *p);
float calculaDelta(float *p);
void calculaRaizes(float *p,float *r,float d);
void mostraRaizes(float *r);
void alocaFloat(float **p,int tam);

int main(){
    float *vet = NULL, *raiz = NULL, delta;
    alocaFloat(&vet, 3);
    alocaFloat(&raiz, 2);
    recebeParametros(vet);
    delta = calculaDelta(vet);
	if(delta<0){
    	printf("Nao ha raizes reais.");
	}
	else{
		calculaRaizes(vet, raiz, delta);
		mostraRaizes(raiz);	
	}
    return 0;
}

void mostraRaizes(float *r){
	int i;
	for(i=0;i<2;i++){
		printf("\nRaiz %i = %.2f",i+1,*(r+i));
	}
}

void calculaRaizes(float *p,float *r,float d){
	*r = (-(*(p+1)) + sqrt(d)) / (2 * (*p));       // x1 = -b + raiz(delta)) / 2a
	*(r+1) = (-(*(p+1)) - sqrt(d)) / (2 * (*p));   // x1 = -b - raiz(delta)) / 2a
}

float calculaDelta(float *p){
      float d;
      //delta = b^2-4ac
      d = pow(*(p+1),2)-4 * (*p) * (*(p+2));
}

void recebeParametros(float *p){
     int i;
     for(i = 0; i < 3; i++){
         printf("Digite o termo %c: ", 'a'+ i);
         scanf("%f",p + i);
     }        
}

void alocaFloat(float **p, int tam){
     if((*p=(float *)realloc(*p,tam*sizeof(float)))==NULL){
         printf("Erro na alocação!");
         exit(1);
     }
     printf("Espaco alocado com sucesso! End= %u\n",*p);
}
