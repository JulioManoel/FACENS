#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void procura(char *pf);

void main(){
	int i;
	char frase[80];
	setlocale(LC_ALL,"portuguese");
	printf("Digite uma frase: ");
	gets(frase);
	procura(frase);
	
}

void procura(char *pf){
	int i,tam,cont=0;
	tam=strlen(pf);
	for(i=0;i<tam;i++){
		if(*(pf+i) == 'x' || *(pf+i) == 'X'){
			cont++;
			break;
		}
	}
	if(cont>0){
		printf("O caracter x foi encontrado");
	}
	else{
		printf("O caracter x não foi encontrado");
	}
}
