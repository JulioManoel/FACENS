#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct aluno{
	char nome[30];
	int idade;
	float nota;
}aluno;

aluno cadastro();

void main(){
	aluno alu[10];
	char op;
	int cont=0,i;
	setlocale(LC_ALL,"portuguese");
	do{
		system("cls");
		printf("\nCadastro de Alunos");
		if(cont<10){
			alu[cont]=cadastro();
			cont++;
		}
		else{
			printf("\nCadastro Lotado");
		}
		printf("\nDeseja continuar <S/N>: ");
		scanf("%c",&op);
		fflush(stdin);
	}while(op!='n' && op!='N');
	for(i=0;i<cont;i++){
		printf("\nAluno %i\nNome: %s\nIdade: %i\nNota: %.2f\n",i+1,alu[i].nome,alu[i].idade,alu[i].nota);
	}
	printf("\n\n");
	system("pause");
}

aluno cadastro(){
	aluno aux;
	printf("\nNome: ");
	gets(aux.nome);
	fflush(stdin);
	printf("\nIdade: ");
	scanf("%i",&aux.idade);
	fflush(stdin);
	printf("\nNota: ");
	scanf("%f",&aux.nota);
	fflush(stdin);
	return aux;
}
