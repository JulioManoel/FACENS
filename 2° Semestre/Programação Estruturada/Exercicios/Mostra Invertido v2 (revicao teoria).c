#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void inverte(char *pf, char *pi);

void main(){
	char frase[80],inv[80];
	setlocale(LC_ALL,"portuguese");
	printf("\nInverte a Frase\n");
	printf("\nDigite a Frase: ");
	gets(frase);
	fflush(stdin);
	inverte(frase,inv);
	printf("\nA frase invertida %s",inv);
}

void inverte(char *pf,char *pi){
	int i,tam;
	tam=strlen(pf);
	pf=pf+tam-1;
	for(i=0;i<tam;i++,pi++,pf--){
		*pi=*pf;
	}
	*pi='\0';
}
