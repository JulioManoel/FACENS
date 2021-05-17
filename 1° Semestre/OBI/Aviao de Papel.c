#include <stdio.h>

int main()
{
	int f, c, fc;
	scanf("%d %d %d", &c, &f, &fc);
	if(c*fc<= f){
		printf("S\n");
	}
	else{
		printf("N\n");
	}
	return 0;
}
