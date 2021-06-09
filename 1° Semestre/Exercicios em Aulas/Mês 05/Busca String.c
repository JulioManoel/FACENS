#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	frase[80],str[80];
	cont,qtde=0,tamf,tams,i,j,pos[80],z,x=0;
	printf("Escreva a frase: ");
	gets(frase);
	printf("Escreva a palavra que gostaria de procurar: ");
	gets(str);
	tamf = strleen(frase);
	tams = strleen(str);
	for(i=0;i<tamf;i++){
		cont=0;
		for(j=0;j<tams;j++){
			if(tolower(frase[i+j] == procurar[j])){
				cont++
				if(cont==tams){
					qtde++
					for(z=0;z<tams;z++,x++){
						pos[x]=i+1+z;
					}
				}		
			}
			else
				j=tams;
		}
	}
	if(qtde==0){
		printf("\nNão ha ocorrencia do string %s na frase\n\n", str);
	}
	else{
		printf("\nO string %s ocorreu %i vezes na frase nas posicoes:\n",str,qtde);
		for(i=0,x=1;i<qtde*tams;i++,x++){
			printf("%i\t",pos[i]);
			if(x==tams){
				printf("\n");
				x=0;
			}
		}
		printf("\n\n");	
	}
	
	system("pause");
	return 0;
}
