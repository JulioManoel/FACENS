#include <stdio.h>
#include <stdlib.h>

float calculaConsumo(float km, float l);

int main(){
	float distancia, volume, consumo;
	printf("Digite a distancia(km) e o volume(litros): ");
	scanf("%f %f",&distancia,&volume);
	consumo = calculaConsumo(distancia, volume);
	printf("Consumo medio = %.2f", consumo);
	system("pause");
	return 0;	
}

float calculaConsumo(float km, float l){
	return (km/l);
}
