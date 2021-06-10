#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para usar a função strlen ()
#include <ctype.h>

int main(){
	char frase[80], letra;
	int i, tam, cont=0; //contar quantas letras iguais a procurada existe na frase
	printf("\nDigite um frase (Max. 100): ");
	gets(frase);
	tam = strlen(frase); //descobri quantas letras tem a frase
	printf("\nDigite uma letra: ");
	fflush(stdin);
	scanf("%c",&letra);	
	for(i=0;i<tam;i++)
		if(toupper(frase[i])==toupper(letra))
			cont++;
	printf("\nA letra %c ocorre %i vezes na frase\n\n",letra,cont);
	system("pause");
	return 0;
}
