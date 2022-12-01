#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void procura(char *pf,char *pl);

void main(){
	char frase[80], proc[80];
	setlocale(LC_ALL,"portuguese");
	printf("Digite uma frase: ");
	gets(frase);
	printf("Digite que frase gostaria de procurar: ");
	gets(proc);
	procura(frase,proc);
	
}

void procura(char *pf,char *pl){
	int i,j,tam,cont=0,tam2,cont2=0;
	tam=strlen(pf);
	for(i=0;i<tam;i++){
		if(*(pf+i) == toupper(*pl) || *(pf+i) == *pl){
			tam2=strlen(pl);
			j=i;
			while(*(pf+j) == toupper(*(pl+1)) || *(pf+i) == *(pl+1)){
				cont2++;
				pl++;
				j++;
			}
			if(cont2 == tam2){
				cont++;
			}
			pl = pl-cont2;
		}
	}
	if(cont>0){
		printf("a frase '%s' foi encontrado %i vezes",*pl,cont);
	}
	else{
		printf("A frase '%s' não foi encontrado",*pl);
	}
}
