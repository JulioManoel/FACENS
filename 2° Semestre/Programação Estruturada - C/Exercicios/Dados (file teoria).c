#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
	int reg;
	char produto[10];
	int qtde;
	int preco;
}dados;

void aloca(dados **p,int tam);
int verifica();
void cadastro(dados *p,int qtde);
void grava();
void mostra(dados *p,int qtde);

void main(){
	dados *pd=NULL;
	char op;
	int qtde;
	aloca(&pd,1);
	qtde = verifica();
	do{
		cadastro(pd,&qtde);
		qtde++;
		printf("\nDeseja continuar <S/N>: ");
		op = getch();
	}while(op!='n' && op!='N');
	mostra(pd,&qtde)
}

void aloca(dados **p,int tam){
	if((*p=(dados*)realloc(*p,tam*sizeof(dados))) == NULL){
		exit(1);
	}
}

int verifica(){
	long int cont=0;
	FILE *fptr=NULL;
	if((fptr = fopen("estoque.bin","rb")) == NULL){
		return cont;
	}
	else{
		fseek(fptr,0,2); //Posiciona o FPTR no fim do arquivo 
		cont = ftell(fptr)/sizeof(dados);
		fclose(fptr);
		return cont;
	}
}

void cadastro(dados *p,int qtde){
	p->reg=qtde;
	printf("\nRegistro: %i",p->qtde);
	printf("\nProduto: ");
	gets(p->produto);
	printf("Qtde: ");
	scanf("%i",&(p->qtde))
	fflush(stdin);
	printf("Preco: ");
	scanf("%i",&(p->preco))
	fflush(stdin);
	grava(p);
}

void grava(dados *p){
	FILE *fptr=NULL;
	if((fptr=fopen("estouqe.bin","ab"))==NULL){
		printf("\nErro ao abrir o arquivo");
	}
	else{
		fwrite(p,sizeof(dados),1,fptr)
	}
	fclose(fptr);
}

void mostra(dados *p,int qtde){
	int i;
	FILE *fptr=NULL;
	system("cls");
	if((fptr = fopen("estoque.bin","rb"))==NULL){
		printf("\Erro ao abrir o arquivo");
	}
	else{
		for(i=0;i<qtde;i++){
			fseek(fptr,i*sizeof(dados),0)
			fread(p,sizeof(dados,1,fptr);
			printf("\nRegistro: %i\nProduto: %s\nQtde: %i\nPreco: %.2f\n",p->reg,p->produto,p->qtde,p->preco);
		}
		fclose(fptr);
	}
}
