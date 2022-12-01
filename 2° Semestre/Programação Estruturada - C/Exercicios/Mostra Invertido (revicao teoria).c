#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void mostra_invertido(char *p);

void main(){
	char frase[80];
	setlocale(LC_ALL,"portuguese");
	printf("\nImprime a frase invertida\n");
	printf("\nDigite a frase: ");
	gets(frase);
	fflush(stdin);
	mostra_invertido(frase);
}

void mostra_invertido(char *p){
	int tam,i;
	tam=strlen(p);
	p=p+tam-1;
	for(i=0;i<=tam;i++,p--){
		printf("%c",*p);
	}	
}
