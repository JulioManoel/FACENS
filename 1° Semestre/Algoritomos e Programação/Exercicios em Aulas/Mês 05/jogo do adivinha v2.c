#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,num[5],acerto=0,nume;
	printf("\nAdivinhe os valores...\n\n");
	system("pause");
	printf("\n");
	srand(time(NULL));//gere numeros diferentes
	for(i=0;i<5;i++){ // 0,1,2,3,4
		num[i] = 1+(rand()%10);
		printf("\t%d",num[i]);
		sleep(0,1);
	}
	for(i=0;i<5;i++){
		system("cls");	
		printf("\nDigite os numeros na ordem que voce viu comecando por %d: ",i);
		scanf("%d", &nume);
		if(i == num[i])
			acerto++;
	}
	printf("\nVoce acertou %d", i);
	return 0;
}
