#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float media(float n1, float n2); //Portótipo

void main(){
	float n1,n2,media;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite dois valores: ");
	scanf("%f %f", &n1,&n2);
	fflush(stdin);
	m = media(n1,n2); //Chamada da função
	printf("\n media = %.2f\n\n", m;
	system("pause");
}

float media(float n1,float n2){
	return (n1+n2)/2;
}
