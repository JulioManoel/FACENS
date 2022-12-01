#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverteInvertido(char s[80],char a[80]);

void main(){
	char texto[80],aux[80];
	printf("Digite uma frase: ");
	gets(texto); //Resebe uma String Inteira
	inverteInvertido(texto, aux); //Chamada
	printf("Resultado: %s",aux);
}

void inverteInvertido(char s[80], char a[80]){
	int i,j, tam=strlen(s);
	for(i=tam-1,j=0;i>=0;i--,j++){
		if(s[i+1] == ' ' || j == 0){
			if(s[i] > 96 && s[i] < 123){
				a[j] = s[i]-32;
			}
		}
		else if(s[i] < 91 && s[i] > 64){
				a[j] = s[i]+32;
		}
		else{
			a[j] = s[i];
		}
	}
	a[j]='\0';
}
