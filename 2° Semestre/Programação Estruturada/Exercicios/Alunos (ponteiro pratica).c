#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
	char loop;
	int q,i=0,num[5], *p_num;
	setlocale(LC_ALL,"portuguese");
	p_num = num; //inicializa��o
	printf("Lendo os elementos do vetor: \n\n");
	do{
		printf("%i� elemento - end %i: ",i+1,p_num);
		scanf("%i",p_num);
		printf("\nDeseja continuar: [S] Sim ou [N] N�o\n\n");
		loop = getch();
		p_num++;
		i++;
		q++;
	}while(loop == 'S' || loop == 's');
	printf("Imprimindo os elementos do vetor: \n\n");
	p_num = num;
	for(i=0;i<q;i++,p_num++){
		printf("%i� elemento - end %i = %i\n",i+1,p_num,*p_num);
	}
	printf("\n");
	system("pause");
}
