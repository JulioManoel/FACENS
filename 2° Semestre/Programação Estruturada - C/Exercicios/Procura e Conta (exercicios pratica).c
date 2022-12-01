#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void procura(char *pf,char *pl,int *pp);

void main(){
	int i, pos[80];
	char frase[80], letra;
	setlocale(LC_ALL,"portuguese");
	printf("Digite uma frase: ");
	gets(frase);
	printf("Digite que letra gostaria de procurar: ");
	scanf("%c",&letra);
	procura(frase, &letra,pos);
	
}

void procura(char *pf,char *pl,int *pp){
	int i,tam,cont=0;
	tam=strlen(pf);
	for(i=0;i<tam;i++){
		if(*(pf+i) == toupper(*pl) || *(pf+i) == *pl){
			*(pp+cont) = i;
			cont++;
		}
	}
	if(cont>0){
		printf("O caracter '%c' foi encontrado %i vezese nas posições ",*pl,cont);
		for(i=0;i<cont;i++,pp++){
			printf("[%i] ",*pp);
		}
	}
	else{
		printf("O caracter %c não foi encontrado",pl);
	}
}
