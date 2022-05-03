#include <stdio.h>
#include <stdlib.h>

int potencia(int b, int e);

void main(){
	int base, expoente, resultado;
	printf("Digite a base e o expoente: ");
	scanf("%d %d",&base,&expoente);
	resultado = potencia(base, expoente);
	printf("Resultado %i", resultado);
}

int potencia(int b, int e){
	int i, r=0;
	for(i=1;i<e;i++){
		r = r+(e*e);
	}
	return r;
}
