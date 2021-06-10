#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //toupper - Maiusculo e tolower - Minusculo
#include <string.h> //strlen - tamanho, strcmp - compara string
#include <locale.h>

void main(){
	char mensagem[80],op,descri[80];
	int crip,i;
	srand(time(NULL));
	setlocale(LC_ALL, "portuguese");
	do{
		system("cls");
		printf("Escolha sua opeção\n");
		printf("\n1- Codificar Senha\n");
		printf("2- Mostrar Mensagem Codificada\n");
		printf("3- Mostrar Mensagem Descodificada\n");
		printf("4- Sair");
		op = getch();
		switch(op){
			case '1':
				system("cls");
				printf("Digite sua mensagem para ser codificada: ");
				gets(mensagem);
				crip = rand() %10 + 1;
				for(i=0;i<strlen(mensagem);i++){
					mensagem[i]+=crip;
				}
				break;
			
			case '2':
				printf("\n\n%s\n\n", mensagem,crip);
				system("pause");
				break;
				
			case '3':
				strcpy(descri, mensagem);
				for(i=0;i<strlen(mensagem);i++){
					descri[i]-=crip;
				}
				printf("\n\n%s\n\n", descri);
				system("pause");
				break;
				
			case '4':
				break;
			
			default:
				printf("\n\nOpecao invalida...\n\n");
				Beep(300, 150);
				system("pause");
		}
	}while(op>'4' ||op<'4');
}
