/*
	Programa que calcula a idade, os dias de viva
	18/03/2021
*/

//Cabe�alho do programa -- diretiva do compilador
#include <stdio.h> //biblioteca padr�o de entrada e saida
#include <locale.h>; //cont�m configura��es do pa�s


int main() //retorna um valor inteiro
{
	int anoNasc, anoAtual, idade, diasVividos, horasVividas, minutosVividos, segundosVividos=0;
	
	setlocale(LC_ALL, "portuguese");
	printf("--------------------\n");
	printf("Programa vers�o 0.007\n");
	printf("--------------------\n");
	printf("\nDigite seu no de nascimento: ");
	scanf("%d",&anoNasc);
	printf("\nDigite o ano atual: ");
	scanf("%d",&anoAtual);
	
	idade = anoAtual - anoNasc;
	diasVividos = idade*365;
	horasVividas = diasVividos*24;
	minutosVividos = horasVividas*60;
	segundosVividos = minutosVividos*60;
	printf("\nSua idade � %d, os dias de vida � %d, as horas vividas � %d e os minutos vividos � %d\n\n",idade,diasVividos, horasVividas, minutosVividos, segundosVividos);
	system("pause");
	return 0; //Se executa e retorna o zero o SO reconhece que houve SUCESSO
}
