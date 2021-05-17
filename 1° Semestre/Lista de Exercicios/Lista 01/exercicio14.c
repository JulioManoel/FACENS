/*
	Este programa calcula a nota final do aluno
	22/03/2021
*/

#include <stdio.h>

int main()
{
	float provaT01, provaT02, provaP01, provaP02, nota = 0;
	printf("\nDigite a nota da primeira prova teorica: ");
	scanf("%f", &provaT01);
	printf("\nDigite a nota da segunda prova teorica: ");
	scanf("%f", &provaT02);
	printf("\nDigite a nota da primeira prova pratica: ");
	scanf("%f", &provaP01);
	printf("\nDigite a nota da segunda prova pratica: ");
	scanf("%f", &provaP02);
	nota = (((provaT01 + provaT02) / 2) * 0.60) + (((provaP01 + provaP02) / 2) * 0.40);
	printf("\nA note final do aluno foi de %.2f", nota);
}
