/*
	Este programa calcula a raiz e a potência
	22/03/2021
*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	float x,p,r = 0;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite um numero para que possa ser mostrada sua raiz e elevada a oitava potência: ");
	scanf("%f", &x);
	p = pow(x, 8);
	r = sqrt(x);
	printf("\nA raiz quadrada do valor é %.2f e a potência é %.2f", r, p);
	return 0 ;
}
