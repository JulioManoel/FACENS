#include <stdio.h>
#include <stdlib.h>

int main(){
	char senha1[7], senha2[7];
	int i, cont1=0, cont2=0;
	printf("\nDigite sua senha: ");
	gets(senha1);
	printf("\nConfirme sua senha: ");
	gets(senha2);
	for(i=0;i<6;i++)
		if(senha1[i]==senha2[i]){
			cont++;
			if(i<3)
				cont1++;
		}
	if(cont==6)
		printf("\nSenha valida\n");
	else if(cont2==3)
		printf("Erro de difitacao");
	else 
		printf("Senha invalida");
	system("pause");
	return 0;
}
