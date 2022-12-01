#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float converter (float t); //Protótipo

void main(){
	float c,f;
	setlocale(LC_ALL, "portuguese");
	printf("\nDigite a temperaturaem Frahrenheit: ");
	scanf("%f",&f);
	fflush(stdin);
	c = converte(f); //Chamada da Função
	printf("\nA temperatura = %.2f° C\n\n");
	system("pause");
}//main

float converte(float t){ //Definição da função
	float celsius;
	celsius = (t-32)/1.8;
	return celsious;
}//converte
