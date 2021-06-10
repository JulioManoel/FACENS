#include <stdio.h>
#include <stdlib.h>
#include <string.h>   //strlen()

int main()
{
char nome[80],mae[80],cidade[20],njedi[6],sjedi[6],cjedi[8];
int i,tam,z,j;
printf("\nNome completo: ");
gets(nome);
fflush(stdin);
printf("\nNome mae: ");
gets(mae);
fflush(stdin);
printf("\nCidade onde vc nasceu: ");
gets(cidade);
fflush(stdin);
//nome Jedi
tam=strlen(nome);   //qtas letras tem o nome
for(i=0;i<3;i++)
  njedi[i]=nome[i];
for(z=tam;z>=0;z--)
  if(nome[z]==' ')
    {
      for(j=0;j<2;j++,i++)
	    njedi[i]=nome[z+1+j];
	  z=-10;	
    }//if
njedi[i]='\0';
printf("\nNome Jedi: %s\n\n",njedi);
system("pause");
return 0;
}//main
