#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned char matriz[10][10];
	int c,l,x,y;
	for(l=0;l<10;l++){
		for(c=0;c<10;c++){
			matriz[l][c] = 1;
			printf(" %c",matriz[l][c]);
		}
		printf("\n");
	}
	srand(time(NULL));
	l = (rand() %10);
	c = (rand() %10);
	matriz[l][c]=2;
	printf("\nOnde esta Wolly: ");
	scanf("%d %d",&x,&y);
	if(x==l && c==y)
		printf("\nAcertou");
	else
		printf("\nErrou\n");
	for(l=0;l<10;l++){
		for(c=0;c<10;c++){
			printf(" %c",matriz[l][c]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
