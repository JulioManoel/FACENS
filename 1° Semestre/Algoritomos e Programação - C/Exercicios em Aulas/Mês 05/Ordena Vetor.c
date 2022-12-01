#include <stdio.h>
#include <stdlib.h>

int main()
{
int mat[100],qtde,i,j,aux;
do
 {
 	printf("\nQuantidade (max.100): ");
 	scanf("%i",&qtde);
 	fflush(stdin);
 }while(qtde<1 || qtde>100);
//leitura do vetor
for(i=0;i<qtde;i++)
  {
  	printf("\nmat[%i]= ",i);
  	scanf("%i",&mat[i]);
  	fflush(stdin);
  }//for
//ordena vetor
for(i=0;i<qtde;i++)
  for(j=i+1;j<qtde;j++)
    if(mat[i]>mat[j])
      {
      	aux=mat[i];
      	mat[i]=mat[j];
      	mat[j]=aux;
      }//if
//mostra o vetor
printf("\nVetor Ordenado:\n");
for(i=0;i<qtde;i++)
  printf("mat[%i]= %i\n",i,mat[i]);
system("pause");
return 0;
}//main
