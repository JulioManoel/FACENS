/**************************************************/
/*                                                */
/*        Implanta��o Dicotomia e Lagrange        */
/*                                                */
/*                  Feito por:                    */
/*  Guilherme Savassa Bernal          RA: 210029  */
/*  Gustavo Luciano Rossi Teixeira    RA: 210333  */
/*  Julio Cesar Bonow Manoel          RA: 210375  */
/*  Rafael Henrique Ramos             RA: 210432  */
/*                                                */
/**************************************************/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

//Fun��es Auxiliares
void menu();
void MMQ();
void calculaMMQ(int curva, int tam,float *x, float *y, float **u, float **esc, float **gaus, float *a);
void mostraMMQ(int curva, int tam,float *x, float *y, float **u, float **esc, float **gaus, float *a);
void trapezios();
void calculaTrapezios(float *h, float *inter, float *mx, float *Fx, float *itr, int n, int grau);
float fTrapezios(float *mx, float x,int grau);
void mostraTrapezios(float h, float *inter, float *mx, float *Fx, float *itr, int n);
void alocaFloat(float **p,int tam);
void creditos();

//Main
void main(){
	setlocale(LC_ALL, "Portuguese");
	system("title Metodos dos Minimos Quadrados e Regra dos Trap�zios");
	menu();
}

//Menu
void menu(){
    int opcao;
	do{
		system("cls");
		printf("=======================================");
		printf("\n                 Menu");
		printf("\n=======================================\n");
    	printf("1- M�todos dos Minimos Quadrados \n2- Regra dos Trap�zios  \n3- Creditos \n4- Sair\n");
    	printf("\nEscolha: ");
    	opcao = getch();
    	switch (opcao) {
    		case '1':
        		system("cls");
        		MMQ();
        		break;
    		case '2':
        		system("cls");
        		trapezios();
        		break;
    		case '3':
        		system("cls");
        		creditos();
        		break;
    		case '4':
        		exit(1);
    		default:
        		printf("\n\nVoce deve escolher uma opcao valida\n");
        		system("pause");
    	}
	}while(opcao != '4');
}

//MMQ
void MMQ(){
	int tam,i,curva,escalar,j;
	float *x=NULL, *y=NULL, **u=NULL,**esc=NULL, **gaus=NULL, *a=NULL;
	char op;
	printf("=======================================");
	printf("\n    Metodos dos Minimos Quadrados");
	printf("\n=======================================\n");
	printf("Obs.: Digite os valores com virgula ao inves de ponto\n\n");
	printf("Digite o n�mero de pontos da tabela x e f(x): ");
	scanf("%i", &tam);
	alocaFloat(&x, tam);
	alocaFloat(&y, tam);
	printf("\nDigite o valor de cada ponto de x:\n");
	for(i=0;i<tam;i++){
		printf("x[%i]: ",i);
		scanf("%f", (x+i));
	}
	printf("\nDigite o valor de cada ponto de y:\n");
	for(i=0;i<tam;i++){
		printf("y[%i]: ",i);
		scanf("%f", (y+i));
	}
	do{
		printf("\nDigite uma op��o (1) reta ou (2) parabola: ");
		scanf("%i",&curva);
		if(curva == 1){
			curva = 2;
		}
		else{
			curva = 3;
		}
		alocaFloat(&a, curva);
		u = malloc(curva * sizeof(float*));
		esc = malloc(curva * sizeof(float*));
		gaus = malloc(curva * sizeof(float*));
		for(i=0;i<curva+1;i++){
			if(i<3 && curva == 2){
				*(esc+i)= malloc(curva*sizeof(float));
				*(gaus+i)= malloc(curva*sizeof(float));
			}
			else if(i<4){
				*(esc+i)= malloc(curva*sizeof(float));
				*(gaus+i)= malloc(curva*sizeof(float));
			}
			*(u+i)= malloc(tam*sizeof(float));
		}
		calculaMMQ(curva, tam, x, y, u, esc, gaus, a);
		mostraMMQ(curva, tam, x, y, u, esc, gaus, a);
		printf("\n\nGostaria de Digitar outro Ponto: (S) Sim ou (N) N�o\n\n");
		op = getch();
	}while(op == 'S' || op == 's');
}

//Calcula MMQ
void calculaMMQ(int curva, int tam,float *x, float *y, float **u, float **esc, float **gaus, float *a){
	int i,j;
	float aux,m2,m3;
	//Criando Vetor
	for(i=0;i<curva;i++){
		for(j=0;j<tam;j++){
			if(i==0){
				*(*(u+i)+j) = 1;
			}
			else{
				*(*(u+i)+j) = pow(*(x+j),i);
			}
		}	
	}
	//Sistema Escalar
	for(i=0;i<curva;i++){
		aux=0;
		for(j=0;j<tam;j++){
			aux+= *(*(u+i)+j) * *(*(u+i)+j);
		}
		*(*(esc+i)+i) = aux;
	}
	aux=0;
	for(j=0;j<tam;j++){
			aux += *(*(u+1)+j);
		}
		*(*(esc+0)+1) = aux;
		*(*(esc+1)+0) = aux;
	if(curva == 3){
		for(i=0;i<curva-1;i++){
			aux=0;
			for(j=0;j<tam;j++){
				aux += *(*(u+2)+j) * *(*(u+i)+j);
			}
			*(*(esc+i)+2) = aux;
			*(*(esc+2)+i) = aux;
		}
	}
	for(i=0;i<curva;i++){
		aux=0;
		for(j=0;j<tam;j++){
			aux += *(y+j) * *(*(u+i)+j);
		}
		*(*(esc+curva)+i) = aux;
	}
	//Elimina��o de Gaus
	m2 = *(*(esc+1)+0) / *(*(esc+0)+0);
	m3 = *(*(esc+2)+0) / *(*(esc+0)+0);
	for(i=0;i<curva+1;i++){
		for(j=0;j<curva+1;j++){
			if(j==0){
				*(*(gaus+i)+j) = *(*(esc+i)+j);
			}
			else if(j==1){
				*(*(gaus+i)+j) = *(*(esc+i)+j) - *(*(esc+i)+0) * m2;
			}
			else{
				*(*(gaus+i)+j) = *(*(esc+i)+j) - *(*(esc+i)+0) * m3;
			}
		}
	}
	//Descobrindo A
	*(a+1) = *(*(gaus+2)+1) / *(*(gaus+1)+1);
	*a = (*(*(gaus+2)+0) - *(a+1) * *(*(gaus+1)+0)) / *(*(gaus+0)+0);
	if(curva == 3){
		*(a+2) = (*(*(gaus+2)+0) - *(a+1) * *(*(gaus+1)+0)) / *(*(gaus+0)+0);
	}
}

//Mostra MMQ
void mostraMMQ(int curva, int tam,float *x, float *y, float **u, float **esc, float **gaus, float *a){
	int i,j;
	printf("\n\n----- Construindo p -----\n");
	printf("\nVetores\n");
	if(curva==2){
		printf("y\tu0\tu1\n");
		for(i=0;i<tam;i++){
			printf("%.2f\t%.2f\t%.2f\n", *(y+i), *(*(u+0)+i), *(*(u+1)+i));
		}
		printf("\n\n---- Sistema Escalar ----\n");
		printf("\nSistema Obtido pelo produto escalar\n");
		for(i=0;i<curva;i++){
			printf("%.2f\t%.2f\t%.2f\n", *(*(esc+0)+i), *(*(esc+1)+i), *(*(esc+2)+i));
		}
		printf("\n\n--- Elimina��o Gauss ----\n");
		printf("\nSistema Obtido pelo produto escalar\n");
		for(i=0;i<curva;i++){
			printf("%.2f\t%.2f\t%.2f\n", *(*(gaus+0)+i), *(*(gaus+1)+i), *(*(gaus+2)+i));
		}
	}
	else{
		printf("y\tu0\tu1\tu2\n");
		for(i=0;i<tam;i++){
			printf("%.2f\t%.2f\t%.2f\t%.2f\n", *(y+i), *(*(u+0)+i), *(*(u+1)+i), *(*(u+2)+i));
		}
		printf("\n\n---- Sistema Escalar ----\n");
		printf("\nSistema Obtido pelo produto escalar\n");
		for(i=0;i<curva;i++){
			printf("%.2f\t%.2f\t%.2f\t%.2f\n", *(*(esc+0)+i), *(*(esc+1)+i), *(*(esc+2)+i), *(*(esc+3)+i));
		}
		printf("\n\n--- Elimina��o Gauss ----\n");
		printf("\nSistema Obtido pelo produto escalar\n");
		for(i=0;i<curva;i++){
			printf("%.2f\t%.2f\t%.2f\t%.2f\n", *(*(gaus+0)+i), *(*(gaus+1)+i), *(*(gaus+2)+i), *(*(gaus+3)+i));
		}
	}
	printf("\n\n--- Resposta: ----\n\n");
	for(i=0;i<curva;i++){
		printf("a%i=%.3f\n",i,*(a+i));
	}
	if(curva==2){
		printf("\nA reta que melhor aproxima a fun��o da tabela � p(x)= %.2fx + %.2f",*(a+1),*a);
	}
	else{
		printf("\nA reta que melhor aproxima a fun��o da tabela � p(x)= %.2fx^2 + %.2f",*(a+2),*(a+1),*a);
	}
	printf("\n\n");
}

//Regra dos Trapezios
void trapezios(){
	int grau,i,n;
	char l='a',op;
	float *mx=NULL,*x=NULL,*inter=NULL,h,*Fx=NULL,itr;
	printf("=======================================");
	printf("\n         Regra dos Trap�zios");
	printf("\n=======================================\n");
	printf("Obs.: Digite os valores com virgula ao inves de ponto\n\n");
	printf("Digite o grau do polin�mio: ");
	scanf("%i", &grau);
	alocaFloat(&mx, grau);
	alocaFloat(&inter, 2);
	printf("\nDigite os valores dos polin�mios: ");
	printf("\n  ");
	for(i=grau;i>=0;i--,l++){
		printf("%cx",l);
		if(i!=0){
			printf("^%i + ",i);
		}
		else{
			printf(" = 0\n\n");
		}
	}
	l='a';
	for(i=grau;i>=0;i--,l++){
		printf("Digite o valor de %c: ",l);
		scanf("%f",(mx+i));
	}
	printf("\nDigite o Intervalo [a,b]\n");
	printf("[a]: ");
	scanf("%f", inter);
	printf("[b]: ");
	scanf("%f", inter+1);
	if(*inter > *(inter+1)){
		*inter += *(inter+1);
		*(inter+1) = *inter - *(inter+1);
		*inter -= *(inter+1);
		printf("\nAten��o - Intervalo alterado\n");
		printf("Ordem correta: [a]=%.2f e [b]=%.2f\n",*inter,*(inter+1));
	}
	do{
		printf("Digite o numero de divisoes do intervalo [a,b]: ");
		scanf("%i",&n);
		alocaFloat(&Fx, n+1);
		calculaTrapezios(&h,inter,mx,Fx,&itr,n,grau);
		mostraTrapezios(h,inter,mx,Fx,&itr,n);
		printf("\n\nGostaria de Digitar outro Ponto: (S) Sim ou (N) N�o\n\n");
		op = getch();
	}while(op == 'S' || op == 's');
}

//Calcula Trapezios
void calculaTrapezios(float *h, float *inter, float *mx, float *Fx, float *itr, int n, int grau){
	int j;
	float x,i,aux=0;
	*h = (*(inter+1) - *inter) / n;
	for(i=0;i<n+1;i++,j++){
		x = *inter + (*h * i);
		*(Fx+j) = fTrapezios(mx, x, grau);
	}
	if(n == 1){
		*itr = (*h / 2) * (*Fx + *(Fx+1));
	}
	else{
		for(j=1;j<n;j++){			
			aux += *(Fx+j);
		}
		*itr = (*h / 2) * ( *Fx + *(Fx+n) + ( 2 * aux ));
		printf("%.4f\n",*Fx);
	}
}

float fTrapezios(float *mx, float x,int grau){
	int i;
	float f=0;
	for(i=grau;i>=0;i--,grau--){
		if(i != 0){
			f += pow((*(mx+i) * x),grau);
		}
		else{
			f+= *(mx+i);
		}
	}
	return f;
}

//Mostra Trapezios
void mostraTrapezios(float h, float *inter, float *mx, float *Fx, float *itr, int n){
	int i;
	printf("\n\n--- Calculo H ---\n");
	printf("h = (%.2f - %.2f) / %i\n",*(inter+1),*inter,n);
	printf("h: %.4f\n\n",h);
	printf("--- Tabela dos Valores ---\n\n");
	printf("------------------\n");
	printf("|   x   |  f(x)  |\n");
	printf("|----------------|\n");
	for(i=0;i<n+1;i++){
		printf("| %.3f | %.3f |\n", (*inter + (h * i)),*(Fx+i));
	}
	printf("------------------\n\n");
	if(n==1){
		printf("IT = %.4f\n", *itr);
	}
	else{
		printf("ITR = %.4f\n", *itr);
	}
}

//Aloca Float
void alocaFloat(float **p,int tam){
	if((*p=(float *)realloc(*p,tam*sizeof(float)))==NULL){
        printf("Erro na aloca��o!");
        system("pause");
        exit(1);
	}
}

//Cr�ditos
void creditos(){
	Beep (150, 1000);
    printf("\n | ********-------****************-------******** |\n");
    printf(" |                                                |\n");
    Beep (150, 1000);
	printf(" |  Guilherme Savassa Bernal        RA:210029     |\n");
    Beep (150, 1000);
    printf(" |  Gustavo Luciano Rossi Teixeira  RA:210333     |\n");
    Beep (150, 1000);
    printf(" |  Julio Cesar Bonow Manoel        RA:210375     |\n");
    Beep (150, 1000);
    printf(" |  Rafael Henrique Ramos           RA:210432     |\n");
    printf(" |                                                |\n");
    printf(" | ********-------****************-------******** |\n\n\n");
    system("pause");
}
