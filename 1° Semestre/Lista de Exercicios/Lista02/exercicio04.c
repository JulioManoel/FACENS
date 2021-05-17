/*
	Este programa calcula a nota de um aluno e fala se foi aprovado ou não
	23/03/2021
*/

#include <stdio.h>
#include <locale.h>

int main()
{
	float nota01, nota02, media = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite o a nota da primeira prova e o da segunda: ");
	scanf("%f %f", &nota01, &nota02);
	media = (nota01 + nota02) / 2;
	if (media >= 5)
	{
		printf("\nAprovado");
	}
	else
	{
		printf("\nFaltou %.2f para ser aprovado", (media-5)*-1);
	}
	return 0;
}
