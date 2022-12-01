#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void inverte(char *pf, char *pi);
char maiuscula(char letra);
char minuscula(char letra);

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
		*pi=minuscula(*pf);
		if(i==0){
			*pi=maiuscula(*pf);	
		}
		if(*pf==' '){
			i++;
			pi++;
			pf--;
			*pi=maiuscula(*pf);
		}
	}
	*pi='\0';
}

char maiuscula(char letra){
	if(letra>='a' && letra<='z'){
		return(letra-32);
	}
	return letra;
}

char minuscula(char letra){
	if(letra>='A' && letra<='Z'){
		return(letra+32);
	}
	return letra;
}
