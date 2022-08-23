/**************************************************/
/*                                                */
/*        Implantação Dicotomia e Lagrange        */
/*                                                */
/*                  Feito por:                    */
/*  Guilherme Savassa Bernal          RA: 210029  */
/*  Gustavo Luciano Rossi Teixeira    RA: 210333  */
/*  Julio Cesar Bonow Manoel          RA: 210375  */
/*  Rafael Henrique Ramos             RA: 210375  */
/*                                                */
/**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <windows.h>


//Funções Auxiliares
void menu();
void dicotomia();
float f(float fValor, int grau, float *x, float *ex);
float CalculaValorK(float a, float b, float erro);
void calculaDicotomia(float a, float b, float *x,float *ex, int grau, float erro);
void lagrange();
float calculaLagrange(float *x, float *fx, float *L, float ponto, int tam);
void mostraLagrange(float *L, float px, float ponto, int tam);
void alocaFloat(float **p,int tam);

//Main
void main(){
	setlocale(LC_ALL, "Portuguese");
	system("title Implementação Dicotomia e Lagrange");
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
    	printf("1- Dictomia \n2- Forma de Lagrange  \n3- Creditos \n4- Sair\n");
    	printf("\nEscolha: ");
    	opcao = getch();
    	switch (opcao) {
    		case '1':
        		system("cls");
        		dicotomia();
        		break;
    		case '2':
        		system("cls");
        		lagrange();
        		break;
    		case '3':
				Beep (150, 1000);
        		system("cls");
        		Beep (150, 1000);
        		printf("\n | ********-------****************-------******** |\n ");
        		printf("|                                                |\n");
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
        		break;
    		case '4':
        		exit(1);
    		default:
        		printf("\n\nVoce deve escolher uma opcao valida\n");
        		system("pause");
    	}
	}while(opcao != '4');
}

//Dicotonomia
void dicotomia(){
	int grau,i;
	float a,b;
	float *x=NULL, *ex=NULL,erro;
	printf("=======================================");
	printf("\n             Dicotomia");
	printf("\n=======================================\n");
	printf("Obs.: Digite os valores com virgula ao inves de ponto\n\n");
	printf("Informe a quantidade de termos: ");
    scanf("%i", &grau);
    alocaFloat(&x, grau);
	alocaFloat(&ex, grau);
		
	for(i=0; i<grau; i++){
        printf("Informe a fator de X e o Expoente do %i° (Exemplo: 1 2 = x^2): ", i+1);
        scanf("%f %f", x+i,ex+i);
    }
    
    //Exibir funcao recebida
    printf("\nA funcao recebida foi: ");
    for(i=0; i<grau; i++){
        printf("%.2fx^%.2f", *(x+i), *(ex+i));
        if(i<grau-1)
            printf(" + ");
        else
            printf(" = 0");
    }
	printf("\nDigite o valor do intervalo (ex. [0;5] = digite 0 5): ");
	scanf("%f %f",&a, &b);
	printf("Digite o valor da precisão: ");
	scanf("%f",&erro);
	
	//Checar se ha raiz no intervalo
    if(f(a,grau,x,ex)*f(b,grau,x,ex)<=0){
        printf("\nHa raiz da funcao no intervalo fornecido. Realizando calculos... ");
        calculaDicotomia(a,b,x,ex,grau,erro);
    }
    else{
        printf("\nNão ha raiz da funcao no intervalo fornecido.\n");
        system("pause");
    }
}

//Calcular o F(x)
float f(float fValor, int grau, float *x, float *ex){
    int i;
	float fResultado = 0;
	for(i=0; i<=grau; i++){
        fResultado = fResultado + *(x+i) * pow(fValor, *(ex+i));
    }
	return fResultado;
}

//Calcula o Valor de K
float CalculaValorK(float a, float b, float erro){
    float fValorK;

    fValorK = (log10(b-a) - log10(erro))/(log10(2));
	return round(fValorK);
}

void calculaDicotomia(float a, float b, float *x, float *ex, int grau, float erro){
	int j;
	float fa, fb, fm, m, k;
	k=CalculaValorK(a, b, erro);
	printf("\n\nValor de K é %.2f\n", k);
	printf("\nPrescione qualquer tecla para avançar com a Tabela", k);
	printf("\n\n| I\t|  a  |  m\t|  b\t|  f(a)\t|  f(m)\t|  f(b)\t| fa*fm\t| fm*fb\t|\n");
    printf("--------------------------------------------------------------------------\n");
    do{
        fa=f(a,grau,x,ex);
        fb=f(b,grau,x,ex);
        m=(b+a)/2;
        fm=f(m,grau,x,ex);
        printf("| %i\t|%.3f |%.3f\t|%.3f\t|%.3f\t|%.3f\t|%.3f\t|%.3f\t|%.3f\t|\n", j, a, m, b, fa, fm, fb, fa*fm, fb*fm);
        getch();
        if(fa*fm<0){
            b=m;
        }
        else if(fb*fm<0){
            a=m;
        }
        else if(fa==0 || fb==0 || fm==0){
            j=k;
        }
        j++;
    }while(sqrt(pow(fm,2))>=erro);
    printf("\n raiz é %.3f e f(m) = %.3f\n\n",m,fm);
    system("pause");
}


//Lagrange
void lagrange(){
	char op;
	int tam,i;
	float *x=NULL, *fx=NULL, *L=NULL, ponto, px;
	printf("=======================================");
	printf("\n             Lagrange");
	printf("\n=======================================\n");
	printf("Obs.: Digite os valores com virgula ao inves de ponto\n\n");
	printf("Digite o número de pontos da tabela de X e f(x): ");
	scanf("%i", &tam);
	alocaFloat(&x, tam);
	alocaFloat(&fx, tam);
	alocaFloat(&L,tam);
	printf("Digite os valores de X para cada ponto:\n");
	for(i=0;i<tam;i++){
		printf("x[%i]: ", i);
		scanf("%f",x+i);
	}
	printf("Digite o valor de cada ponto de F(x):\n");
	for(i=0;i<tam;i++){
		printf("f(x[%i]): ", i);
		scanf("%f",fx+i);
	}
	do{
		printf("Digite o ponto de interpolação: ");
		scanf("%f", &ponto);
		px = calculaLagrange(x, fx, L,ponto, tam);
		mostraLagrange(L, px, ponto, tam);
		printf("\n\nGostaria de Digitar outro Ponto: (S) Sim ou (N) Não\n\n");
		op = getch();
	}while(op == 'S' || op == 's');
}

//Calcula Lagrange
float calculaLagrange(float *x, float *fx, float *L, float ponto, int tam){
	int i,j;
	float aux;
	for(i=0;i<tam;i++){
		*(L+i) = 1;
		for(j=0;j<tam;j++){
			if(j!=i){
				*(L+i) = *(L+i) * ((ponto - *(x+j)) / (*(x+i) - *(x+j)));
			}
		}
		aux += *(fx+i) * *(L+i);
	}
	return aux;
}

void mostraLagrange(float *L, float px, float ponto ,int tam){
	int i;
	printf("\n");
	for(i=0;i<tam;i++){
		printf("L%i = %.2f\n",i,*(L+i));
	}
	printf("\np(%.2f) = %.4f\n",ponto,px);
}

//Aloca Float
void alocaFloat(float **p,int tam){
	if((*p=(float *)realloc(*p,tam*sizeof(float)))==NULL){
        printf("Erro na alocação!");
        system("pause");
        exit(1);
	}
}
