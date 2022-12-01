#include <stdio.h>
#include <ctype.h>

int main(){
	float m[40][5];
	int i=0,j;
	char resp
	
	do{
		printf("\nAluno %i\n", i+1);
		for(j=0;j<4;j++){
			printf("Digite a nota %i: ",j+1);
			scanf("%f", &m[i][j]);
		}
		i++;
		printf("Deseja continuar? S-Sim N-Nao:");
		resp = getch();
	}while(toupper(resp) == 'S' && i<40);
	return 0;
}
