#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0,i1,i2,i3,i4,i5,rand1,rand2,rand3,rand4,rand5;
	printf("\nAdivinhe os valores...\n\n");
	system("pause");
	printf("\n");
	srand(time(NULL));
	rand1 = 1+(rand()%10);
	rand2 = 1+(rand()%10);
	rand3 = 1+(rand()%10);
	rand4 = 1+(rand()%10);
	rand5 = 1+(rand()%10);
	printf("\t%d",rand1);
	sleep(0,1);
	printf("\t%d",rand2);
	sleep(0,1);
	printf("\t%d",rand3);
	sleep(0,1);
	printf("\t%d",rand4);
	sleep(0,1);
	printf("\t%d",rand5);
	sleep(1);
	system("cls");
	printf("\nQuais sao os numeros na sequencia mostrada?\n");
	scanf("%d %d %d %d %d", &i1,&i2,&i3,&i4,&i5);
	if(i1 == rand1)
		i++;
	if(i2 == rand2)
		i++;
	if(i3 == rand3)
		i++;
	if(i4 == rand4)
		i++;
	if(i5 == rand5)
		i++;
	printf("\nVoce acertou %d", i);
	return 0;
}
