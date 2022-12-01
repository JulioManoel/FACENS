/**************************************************/
/*                                                */
/*      Sistema de Venda e Controle de Estoque    */
/*                                                */
/*                  Feito por:                    */
/*         Douglas Braz Machado, RA 210034        */
/*       Julio Cesar Bonow Manoel, RA 210375      */
/*   Lucas Affonso Antunes de Brito, RA 210171    */
/*                                                */
/**************************************************/

#include <stdio.h> //Entrada e Saida
#include <stdlib.h> //System
#include <string.h> //Comparação de String
#include <locale.h> //Acentuação

//Struct Concessionária  -------------------------------------------------------------------------------------------
typedef struct endereco{
	char logradouro[80];
	char bairro[15];
	char CEP[10];
	char cidade[15];
	char estado[3];
	char fone[12];
	char email[40];
}endereco;
typedef struct infocarro{
	char sigla;
	int regcarro;
}infocarro;
union dadoscarro{
	char sigla;
	struct infocarro reservado;
};
typedef struct loja{
	int regloja; //gerar automático
	char nome[30];
	char CNPJ[19];
	struct endereco end;
	int sold;
	int reserved;
	union dadoscarro tabela[3];
}loja;

//Struct Montadora ------------------------------------------------------------------------------------------------
typedef struct infoloja{ 
	char sigla; 
	char CNPJ[19]; 
}infoloja; 
union dadosloja{ 
	char sigla; 
	infoloja reserva; 
}; 
typedef struct montadora{ 
	int regcarro; //gerar automático 
	char modelo[20]; 
	char cor[10]; 
	float  valor; 
	union dadosloja status; 
}montadora; 

//Struct Histórico ------------------------------------------------------------------------------------------------
struct data{ 
	int dia;  
	int mes;  
	int ano;  
}; 
typedef struct historicoVendas{ 
	int reghist; 
    int regcarro; 
    char modelo[20]; 
	char cor[10]; 
	float valor;  
	int regloja; 
	char nome[30]; 
	char cnpj[19]; 
	struct data dataVenda; 
}historico;

//Prototipo Funções Auxiliares ------------------------------------------------------------------------------------
void menu();
void verificaQtde(int *qtde);
//Loja ------------------------------------------------------------------------------------------------------------
void aloca(loja **p,int tam);
void cadastraCon(loja *p, int qtde);
void editaCadastroCon(loja *p, int qtde);
void consultaCon(loja *p, int qtde);
//Montadora -------------------------------------------------------------------------------------------------------
void verificaQtdeMon(int *qtde);//verifica montadora
void alocaMon(montadora **p,int tam);//alocação dinamica
void cadastraMon(montadora *p, int qtde);//cadastro carro
void editaCadastroMon(montadora *p, int qtde);//edita cadastro do carro
void consultaTotalMon(montadora *p, int qtde);//consulta total
void consultaStatusMon(montadora *p, int qtde);//consulta parcial Status
void consultaModeloMon(montadora *p, int qtde);//consulta parcial Modelo
//Venda -----------------------------------------------------------------------------------------------------------
void reserva(loja *pCon, montadora *pMon, int qtde);
void venda(loja *pCon, montadora *pMon, historico *pHis, int qtde);
//Histórico -------------------------------------------------------------------------------------------------------
void verificaQtdeHis(int *qtde);//verifica histórico
void alocaHis(historico **p,int tam);
void cadastraHis(loja *pCon, montadora *pMon, historico *pHis);
void consultaHis(historico *p);
void consultaHisCar(historico *p);
void consultaHisCon(historico *p);

//Corpo Principal--------------------------------------------------------------------------------------------------
void main(){
	setlocale(LC_ALL, "portuguese"); //set linguagem
	system("title Sistema de Estoque de uma Montadora de Veículos"); //título
	system("mkdir Dados"); //cria pasta
	menu(); //chama função Menu
}//main

void menu(){
	//Variaveis
	char op; //operador de controle char para economizar memoria
	loja *pCon=NULL;
	montadora *pMon=NULL;
	historico *pHis=NULL;
	int qtde=0;
	aloca(&pCon,1);
	alocaMon(&pMon,1);
	alocaHis(&pHis,1);
	do{
		system("cls"); //limpa terminal windows	
				
		//MENU Principal------------------------------------------------									
		printf("=======================================");
		printf("\n                 Menu");                 
		printf("\n=======================================\n");		
		printf("\nDigite o número da sua opção: \n");             
		printf("\n[1]- Concessionaria");
		printf("\n[2]- Montadora");
		printf("\n[3]- Sair\n");
		op = getch(); //retorna a tecla digitada sem mostra-la
		switch (op){
					//Switch Case 1 -------------------------------------------------------------------------------
			case '1':
				do{
					verificaQtde(&qtde);
					system("cls"); //limpa terminal windows
					
					printf("=======================================");
					printf("\n                 Concessionaria");
					printf("\n=======================================\n");
					printf("\nDigite o número da sua opção: \n");
					printf("\n[1]- Cadastrar");
					printf("\n[2]- Editar Cadastro");
					printf("\n[3]- Consultar - CNPJ");
					printf("\n[4]- Reservar Carros");
					printf("\n[5]- Finalizar Venda");
					printf("\n[6]- Consultar Historico");
					printf("\n[7]- Voltar\n");
					op = getch(); //retorna a tecla digitada sem mostra-la
					switch(op){ 
						case '1':
							if(qtde < 5){
								cadastraCon(pCon,qtde+1);//Limita Cadastros
							}
							else{
								printf("Todos os 5 cadastros já foram realizados");
							}
							break;
						case '2':
							editaCadastroCon(pCon,qtde);
							break;						
						case '3':
							consultaCon(pCon,qtde);
							break;
						case '4':
							reserva(pCon,pMon,qtde);
							break;
						case '5':
							venda(pCon,pMon,pHis,qtde);
							break;
						case '6':
							consultaHis(pHis);
							break;
						case '7':
							menu();
							break;
						default:
							printf("\nOpcao invalida! Tente Novamente!\n");
                			Beep(1500, 200); //beep com frequência de 1500Hz e duração de 200ms 
                			system("pause"); //pausa a tela	
					}	
				}while(op!='7');
				break; //fim case 1
				
					//Switch Case 2 -------------------------------------------------------------------------------------------
			case '2': 
				do{
					verificaQtdeMon(&qtde);
					system("cls"); //limpa terminal windows
					printf("=======================================");
					printf("\n                 Montadora");
					printf("\n=======================================\n");
					printf("\nDigite o número da sua opção: \n");
					printf("\n1- Cadastrar Novo Carro");
					printf("\n2- Editar Cadastro");
					printf("\n3- Consultar - Total");
					printf("\n4- Consultar - Parcial Status");
					printf("\n5- Consultar - Parcial Modelo");
					printf("\n6- Voltar\n");
					op = getch();
					switch(op){ //retorna a tecla digitada sem mostra-la
						case '1':
							if(qtde < 50){ //limita cadastro carro
								cadastraMon(pMon,qtde+1);
							}
							else{
								printf("Todos os 50 cadastros já foram realizados");
							}
							break;
						case '2':
							editaCadastroMon(pMon,qtde);
							break;
						case '3':
							consultaTotalMon(pMon,qtde);
							break;
						case '4':
							consultaStatusMon(pMon,qtde);
							break;
						case '5':
							consultaModeloMon(pMon,qtde);
							break;
						case '6':
							menu();
							break;
						default:
							printf("\nOpcao invalida! Tente Novamente!\n");
                			Beep(1500, 200); //beep com frequência de 1500Hz e duração de 200ms 
                			system("pause"); //pausa a tela	
					}	
				}while(op!='6');
				break; //fim case 2
				
				//Switch Case 3 -------------------------------------------------------------------------------------------
			case '3':
                printf("\nFinalizando...\n");
                exit(0); //finaliza programa
                break; //fim case 4
			default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                Beep(1500, 200); //beep com frequência de 1500Hz e duração de 200ms 
                system("pause"); //pausa a tela
        }
    }while(op!='3'); //fim do-while
}

//Verifica quantidade ---------------------------------------------------------------------------------------------------
void verificaQtde(int *qtde){
	FILE *file=NULL;
	if((file=fopen("Dados/concessionaria.bin","rb"))==NULL){
		printf("\nArquivo Inxistente\n");
		system("pause");//pausa a tela
	}	
	else{
		fseek(file,0,2); //modifica o indicador de posição
		*qtde=ftell(file)/sizeof(loja);
		fclose(file); //encerra o fluxo
	}
}

void aloca(loja **p,int tam){
	if((*p = (loja*)realloc(*p,tam*sizeof(loja))) == NULL){
		printf("\nErro na Alocação");
		system("pause"); //pausa a tela
		exit(1); //retorna
	}
}

//Cadastra a concessionária ---------------------------------------------------------------------------------------------------
void cadastraCon(loja *p,int qtde){
	int i;
	FILE *file=NULL;
	if((file=fopen("Dados/concessionaria.bin","ab"))==NULL){
		system("cls");
		printf("\nArquivo não Existe. Será criado um novo");
		system("pause");
	}
	system("cls");//limpa terminal windows
	printf("=======================================");
	printf("\n          Concessionaria Cadastro");
	printf("\n=======================================\n");
	printf("\nNumero de Registro: %i", qtde);
	p->regloja=qtde;
	printf("\nNome (Max. 30): ");
	gets(p->nome);
	printf("CNPJ: ");
	gets(p->CNPJ);
	printf("Rua (Max. 80): ");
	gets(p->end.logradouro);
	printf("Bairro (Max. 15): ");
	gets(p->end.bairro);
	printf("CEP: ");
	gets(p->end.CEP);
	printf("Cidade (Max. 15): ");
	gets(p->end.cidade);
	printf("Estado (Max. 3): ");
	gets(p->end.estado);
	printf("Telefone (Max. 12): ");
	gets(p->end.fone);
	printf("E-mail (Max. 40): ");
	gets(p->end.email);
	p->sold=0;
	p->reserved=0;
	for(i=0;i<3;i++){
		(p->tabela+i)->sigla='L';
	}
	fwrite(p, sizeof(loja),1,file); //indica os bytes ocupados por "loja"
	fclose(file);
}

//Edita o cadastro da concessionária ---------------------------------------------------------------------------------------------------
void editaCadastroCon(loja *p, int qtde){
	FILE *file=NULL;
	char aux[19],op;
	int i;
	if((file=fopen("Dados/concessionaria.bin","rb+"))==NULL){ //caso nulo
		printf("\nArquivo Inixistente");
		system("pause"); //pausa a tela
	}	
	else{ //caso não nulo
		system("cls");//limpa terminal windows 
		printf("=======================================");
		printf("\n        Editar Concessionária");
		printf("\n=======================================\n");
		printf("Digite o CNPJ da concessionária: ");
		gets(aux);
		for(i=0;i<qtde;i++){
			fseek(file,i*sizeof(loja),0);
			fread(p, sizeof(loja),1,file);
			if(strcmp(p->CNPJ,aux)==0){
				do{ //retorna os valores, a fim de alterá-los
					system("cls"); //limpa o terminal windows
					printf("=======================================");
					printf("\n        Editar Concessionária");
					printf("\n=======================================\n");
					printf("\nNúmero do Registro: %i - Nome da Concessionária: %s",p->regloja,p->nome);
					printf("\nRua: %s - Bairro: %s - CEP: %s",p->end.logradouro,p->end.bairro,p->end.CEP);
					printf("\nCidade: %s - Estado: %s",p->end.cidade,p->end.estado);
					printf("\nFone: %s - Email: %s",p->end.fone,p->end.email);				
					printf("\nNúmero de Carros Vendidos: %i",p->sold);
					printf("\nNúmero de Carros Reservados: %i\n\n",p->reserved);
					printf("\nDigite o número da sua opção: \n");
					printf("\n[1]- Editar Nome");
					printf("\n[2]- Editar CNPJ");
					printf("\n[3]- Salvar Alterações\n");
					op = getch(); //retorna a tecla digitada
					switch(op){
						case '1':
							printf("\nDigite o novo nome (Max. 30): ");
							gets(p->nome); //aponta em direção nome
							break;
						case '2':
							printf("\nDigite o novo CNPJ: ");
							gets(p->CNPJ); //aponta em direção CNPJ
							break;
						case '3':
							fseek(file,i*sizeof(loja),0);
							fwrite(p,sizeof(loja),1,file);
							break;
						default:
							printf("\nOpcao invalida! Tente Novamente!\n");
                			Beep(1500, 200); //beep com frequência de 1500Hz e duração de 200ms 
                			system("pause"); //pausa a tela
							break;
					}
				}while(op!='3'); //fim do while
			}
		fclose(file); //encerra o fluxo
		}
	}
}

//Consulta a concessionária ---------------------------------------------------------------------------------------------------
void consultaCon(loja *p, int qtde){
	FILE *file=NULL;
	char aux[19];
	int i;
	if((file=fopen("Dados/concessionaria.bin","rb"))==NULL){
		printf("\nArquivo Inixistente");
		system("pause"); //pausa a tela
	}	
	else{
		system("cls");//limpa terminal windows
		printf("=======================================");
		printf("\n          Concessionaria Consulta");
		printf("\n=======================================\n");
		printf("Digite o CNPJ da concessionária: ");
		gets(aux);
		for(i=0;i<qtde;i++){
			fseek(file,i*sizeof(loja),0);
			fread(p, sizeof(loja),1,file);
			if(strcmp(p->CNPJ,aux)==0){
				
				//exibe valores amrmazenados
				printf("\nNome da Concessionária: %s\n",p->nome);
				printf("Número de Carros Vendidos: %i\n",p->sold);
				printf("Número de Carros Reservados: %i\n\n",p->reserved);
				system("pause"); //pausa a tela
			}
		}
		fclose(file); //encerra fluxo
	}
}

//Verifica a quantidade da montadora ----------------------------------------------------------------------------------
void verificaQtdeMon(int *qtde){
	FILE *file=NULL;
	if((file=fopen("Dados/carro.bin","rb"))==NULL){
		printf("\nArquivo Inixistente\n");
		system("pause"); //pausa a tela
	}	
	else{
		fseek(file,0,2); //altera indicador
		*qtde=ftell(file)/sizeof(montadora); //bytes montadora
		fclose(file); //fim do fluxo
	}
}

//Acola a montadora ---------------------------------------------------------------------------------------------------
void alocaMon(montadora **p,int tam){
	if((*p = (montadora*)realloc(*p,tam*sizeof(montadora))) == NULL){ //caso nulo | altera tamanho do bloco de memórica alocado
		printf("\nErro na Alocação");
		system("pause"); //pausa a tela
		exit(1); //retorna 
	}
}

//Cadastra a montadora -------------------------------------------------------------------------------------------------
void cadastraMon(montadora *p,int qtde){
	FILE *file=NULL;
	if((file=fopen("Dados/carro.bin","ab"))==NULL){ //caso não houver registro
		system("cls"); //limpa terminal windows 
		printf("\nArquivo não Existe, Sera criado...\n");
		system("pause"); //pausa a tela
	}
	//inicia registro
	system("cls");//limpa terminal windows
	printf("=======================================");
	printf("\n          Cadastro Carro");
	printf("\n=======================================\n");
	printf("\nNumero de Registro: %i", qtde);
	p->regcarro=qtde;
	printf("\nModelo (Max. 20): ");
	gets(p->modelo);
	printf("Cor (Max. 10): ");
	gets(p->cor);
	printf("Preço: ");
	scanf("%f",&p->valor);
	fflush(stdin);
	p->status.sigla='L';
	fwrite(p, sizeof(montadora),1,file);
	fclose(file); //encerra fluxo
}
//Edita o cadastro da montadora ---------------------------------------------------------------------------------------
void editaCadastroMon(montadora *p, int qtde){
	FILE *file=NULL;
	char op; //variável de opção
	int i,reg;
	if((file=fopen("Dados/carro.bin","rb+"))==NULL){
		printf("\nArquivo Inixistente");
		system("pause"); //pausa a tela
	}	
	else{	
		system("cls"); //limpa terminal windows 
		printf("=======================================");
		printf("\n        Editar Carros");
		printf("\n=======================================\n");
		printf("Digite o REGISTRO do Carro: ");
		scanf("%i",&reg);
		for(i=0;i<qtde;i++){
			fseek(file,i*sizeof(montadora),0);
			fread(p, sizeof(montadora),1,file);
			if(p->regcarro==reg){
				do{//abre alteração da alocação
					system("cls"); //limpa terminal windows 
					printf("=======================================");
					printf("\n        Editar Carros");
					printf("\n=======================================\n");
					printf("\nNúmero do Registro: %i - Modelo: %s - Cor: %s",p->regcarro,p->modelo,p->cor);
					printf("\nValor: %.2f - Status: %s\n\n",p->valor,p->status);
					printf("\nDigite o número da sua opção:\n");
					printf("\n[1]- Editar Modelo");
					printf("\n[2]- Editar Cor");
					printf("\n[3]- Editar Valor");
					printf("\n[4]- Salvar Alterações\n");
					op = getch(); //retorna a tecla digitada		
					switch(op){
						case '1':
							printf("\nDigite o novo modelo (Max. 20): ");
							gets(p->modelo);
							break;
						case '2':
							printf("\nDigite a nova cor (Max. 10): ");
							gets(p->cor);
							break;
						case '3':
							printf("\nDigite o novo valor: ");
							scanf("%f",&p->valor);
							break;
						case '4':
							fseek(file,i*sizeof(montadora),0);
							fwrite(p,sizeof(montadora),1,file);
							break;
						default:
							printf("\nOpcao invalida! Tente Novamente!\n");
                			Beep(1500, 200); //beep com frequência de 1500Hz e duração de 200ms 
                			system("pause"); //pausa a tela
							break;
					}
				}while(op!='4'); //fim do while
			}
		}
		fclose(file); //encerra o fluxo
	}
}

//Consulta o total da montadora ------------------------------------------------------------------------------------------
void consultaTotalMon(montadora *p, int qtde){
	FILE *file=NULL;
	int i;
	if((file=fopen("Dados/carro.bin","rb"))==NULL){ //caso nulo
		printf("\nArquivo Inixistente\n");
		system("pause"); //pausa a tela
	}	
	else{
		system("cls");//limpa terminal windows
		printf("=======================================");
		printf("\n           Consulta  Total");
		printf("\n=======================================\n");
		for(i=0;i<qtde;i++){ //estrutura a repetição do registro
			fseek(file,i*sizeof(montadora),0);
			fread(p, sizeof(montadora),1,file);
			printf("\nNúmero de Registro: %i - Modelo: %s - Cor: %s - Preço: %.2f - Status: %s",p->regcarro,p->modelo,p->cor,p->valor,p->status);
		}
		printf("\n\n");
		system("pause"); //pausa a tela
		fclose(file); //encerra o fluxo
	}
}

//Consulta o status da montadora -----------------------------------------------------------------------------------------
void consultaStatusMon(montadora *p, int qtde){
	FILE *file=NULL;
	char aux;
	int i;
	if((file=fopen("Dados/carro.bin","rb"))==NULL){
		printf("\nArquivo Inixistente\n");
		system("pause");
	}	
	else{
		system("cls");//limpa terminal windows
		printf("=======================================");
		printf("\n           Consulta  Status");
		printf("\n=======================================\n");
		printf("Escolha entre [L]Livre ou [R]Reservado");
		aux = toupper(getch());
		for(i=0;i<qtde;i++){
			fseek(file,i*sizeof(montadora),0);
			fread(p, sizeof(montadora),1,file);
			if(p->status.sigla == aux){
				printf("\nNúmero de Registro: %i - Modelo: %s - Cor: %s - Preço: %.2f",p->regcarro,p->modelo,p->cor,p->valor);
			}
		}
		printf("\n");
		system("pause"); //pausa a tela
		fclose(file); //encerra o fluxo
	}
}

//Consulta o modelo da montadpra ---------------------------------------------------------------------------------------------
void consultaModeloMon(montadora *p, int qtde){
	FILE *file=NULL;
	char aux[20];
	int i;
	if((file=fopen("Dados/carro.bin","rb"))==NULL){
		printf("\nArquivo Inixistente\n");
		system("pause"); //pausa a tela
	}	
	else{
		system("cls");//limpa terminal windows
		printf("=======================================");
		printf("\n           Consulta  Status");
		printf("\n=======================================\n");
		printf("Digite o Modelo: ");
		gets(aux);
		for(i=0;i<qtde;i++){
			fseek(file,i*sizeof(montadora),0);
			fread(p, sizeof(montadora),1,file);
			if(strcmp(strupr(p->modelo),strupr(aux))==0){
				printf("\nNúmero de Registro: %i - Modelo: %s - Cor: %s - Preço: %.2f",p->regcarro,p->modelo,p->cor,p->valor);
			}
		}
		printf("\n\n");
		system("pause"); //pausa a tela
		fclose(file); //encerra o fluxo
	}
}

void reserva(loja *pCon, montadora *pMon, int qtde){
	FILE *fileCon=NULL,*fileMon=NULL;
	char aux[19],op;
	int i,j,reg,qtdeMon;
	if((fileCon=fopen("Dados/concessionaria.bin","rb+"))==NULL){
		printf("\nArquivo Inixistente");
		system("pause"); //pausa a tela
	}
	else{
		system("cls");//limpa terminal windows
		printf("=======================================");
		printf("\n          Reserva Carro");
		printf("\n=======================================\n");
		printf("Digite o CNPJ da concessionária: ");
		gets(aux);
		for(i=0;i<qtde;i++){
			fseek(fileCon,i*sizeof(loja),0);
			fread(pCon,sizeof(loja),1,fileCon);
			if(strcmp(pCon->CNPJ,aux)==0){
				printf("Conecessionária: %s\n",pCon->nome);
				if(pCon->reserved<3){
					if((fileMon=fopen("Dados/carro.bin","rb+"))==NULL){
						printf("\nArquivo Inixistente\n");
						system("pause"); //pausa a tela
					}	
					else{
						printf("\nGostara de Consultar os Carros Livres: [S]Sim [N]Não\n");
						op = toupper(getch());
						verificaQtdeMon(&qtdeMon);
						if(op != 'N'){				
							for(j=0;j<qtdeMon;j++){
								fseek(fileMon,j*sizeof(montadora),0);
								fread(pMon,sizeof(montadora),1,fileMon);
								if(pMon->status.sigla == 'L'){
									printf("Número de Registro: %i - Modelo: %s - Cor: %s - Preço: %.2f\n",pMon->regcarro,pMon->modelo,pMon->cor,pMon->valor);
								}
							}
						}
						//aloca reserva -------------------------------------------------------------------------------------
						printf("\nDigite o REGISTRO do carro que deseja reservar: ");
						scanf("%i",&reg);
						for(j=0;j<qtdeMon;j++){
							fseek(fileMon,j*sizeof(montadora),0);
							fread(pMon,sizeof(montadora),1,fileMon);
							if(pMon->regcarro == reg && pMon->status.sigla == 'L'){
								switch(pCon->reserved){
									case 0:
										pCon->reserved++;
										pCon->tabela[0].reservado.sigla='R';
										pCon->tabela[0].reservado.regcarro=reg;
										pMon->status.reserva.sigla='R';
										strcpy(pMon->status.reserva.CNPJ, aux);
										break;
									case 1:
										pCon->reserved++;
										pCon->tabela[1].reservado.sigla='R';
										pCon->tabela[1].reservado.regcarro=reg;
										pMon->status.reserva.sigla='R';
										strcpy(pMon->status.reserva.CNPJ, aux);
										break;
									case 2:	
										pCon->reserved++;
										pCon->tabela[2].reservado.sigla='R';
										pCon->tabela[2].reservado.regcarro=reg;
										pMon->status.reserva.sigla='R';
										strcpy(pMon->status.reserva.CNPJ, aux);
										break;
								}
								fseek(fileCon, i*sizeof(loja),0);
								fwrite(pCon, sizeof(loja),1,fileCon);
								fseek(fileMon, j*sizeof(montadora),0);
								fwrite(pMon, sizeof(montadora),1,fileMon);
								printf("\nGravação ocorreu com Sucesso\n");
								system("pause"); //pausa a tela
							}
						}
					}
					fclose(fileMon); //encerra o fluxo
				}
			}
		}
		fclose(fileCon); //encerra o fluxo
	}
}//fim do void 

void venda(loja *pCon, montadora *pMon, historico *pHis, int qtde){
	FILE *fileCon,*fileMon=NULL;
	char aux[19],op;
	int i,j,k,reg;
	if((fileCon=fopen("Dados/concessionaria.bin","rb+"))==NULL){
		printf("\nArquivo Inixistente");
		system("pause"); //pausa a tela
	}	
	else{
		system("cls"); //limpa terminal windows 
		printf("=======================================");
		printf("\n          Venda do Carro");
		printf("\n=======================================\n");
		printf("Digite o CNPJ da concessionária: ");
		gets(aux);
		for(i=0;i<qtde;i++){
			fseek(fileCon,i*sizeof(loja),0);
			fread(pCon, sizeof(loja),1,fileCon);
			if(strcmp(pCon->CNPJ,aux)==0){
				if(pCon->reserved<=3){
					if((fileMon=fopen("Dados/carro.bin","rb+"))==NULL){
						printf("\nArquivo Inixistente\n");
						system("pause");
					}	
					else{
						printf("\n\nDigite o REGISTRO do carro que deseja finalizar a venda: ");
						scanf("%i",&reg);
						for(j=0;j<qtde;j++){
							fseek(fileMon,j*sizeof(montadora),0);
							fread(pMon, sizeof(montadora),1,fileMon);
							if(pMon->regcarro == reg && pMon->status.reserva.sigla == 'R' && strcmp(pMon->status.reserva.CNPJ,aux)==0){
								for(k=0;k<3;k++){
									if(pCon->tabela[k].reservado.regcarro == reg){
										pCon->reserved--;
										pCon->sold++;
										pCon->tabela[k].sigla='L';
										pMon->status.sigla='L';
										cadastraHis(pCon,pMon,pHis);
										strcpy(pMon->modelo, "vago");
										strcpy(pMon->cor, "vago");
										break;
									}
								}
								fseek(fileCon, i*sizeof(loja),0);
								fwrite(pCon, sizeof(loja),1,fileCon);
								fseek(fileMon, j*sizeof(montadora),0);
								fwrite(pMon, sizeof(montadora),1,fileMon);
							}
						}
						fclose(fileMon);
					}
				}
			}
		}
		fclose(fileCon);
	}
}

//verifica a quantidade do histórico ---------------------------------------------------------------------------------------
void verificaQtdeHis(int *qtde){
	FILE *file=NULL;
	if((file=fopen("Dados/historico.bin","rb"))==NULL){ //caso nulo
		printf("\nArquivo Inixistente\n");
		system("pause"); //pausa a tela
	}	
	else{
		fseek(file,0,2); //altera indicador
		*qtde=ftell(file)/sizeof(historico); //bytes histórico
		fclose(file); //encerra histórico
	}
}

//Aloca o histórico --------------------------------------------------------------------------------------------------------
void alocaHis(historico **p,int tam){
	if((*p = (historico*)realloc(*p,tam*sizeof(historico))) == NULL){ //caso nulo
		printf("\nErro na Alocação");
		system("pause");//pausa a tela
		exit(1);//retorna
	}
}

//Cadastra o histórico -----------------------------------------------------------------------------------------------------
void cadastraHis(loja *pCon, montadora *pMon, historico *pHis){
	int qtde;
	FILE *file=NULL;
	verificaQtdeHis(&qtde);
	if((file=fopen("Dados/historico.bin","ab"))==NULL){
		system("cls");
		printf("\nArquivo não Existe, Sera criado...\n");
		system("pause");//pausa a tela
	}
	system("cls");//limpa terminal windows
	printf("=======================================");
	printf("\n          Registrando Venda");
	printf("\n=======================================\n");
	printf("\nDigite o data (dd/mm/ano): ");
	scanf("%i/%i/%i",&pHis->dataVenda.dia,&pHis->dataVenda.mes,&pHis->dataVenda.ano);
	//Ponteiros direcionados
	pHis->reghist=qtde; 
	pHis->regcarro=pMon->regcarro; 
	strcpy(pHis->modelo, pMon->modelo);
	strcpy(pHis->cor, pMon->cor);                      
	pHis->valor=pMon->valor;
	pHis->regloja=pCon->regloja;
	strcpy(pHis->nome, pCon->nome);
	strcpy(pHis->cnpj, pCon->CNPJ);
	fwrite(pHis, sizeof(historico),1,file);
	fclose(file);
}

//Consulta o histórico ------------------------------------------------------------------------------------------------------
void consultaHis(historico *p){
	char op;
	do{
		system("cls"); //limpa terminal windows
		printf("=======================================");
		printf("\n          Historico de Vendas");
		printf("\n=======================================\n");
		printf("\nDigite o número da sua opção: \n");
		printf("\n[1]- Carros comprados por concessionária");
		printf("\n[2]- Concessionárias que compraram determinado modelo de carro");
		printf("\n[3]- Voltar\n");
		op = getch(); //retorna a tecla digitada sem mostra-la
		switch (op){
			case '1':
				consultaHisCar(p);
				break; //fim case 1
			case '2': 
				consultaHisCon(p);
				break; //fim case 2
			case '3':
                menu();
                break; //fim case 4
			default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                Beep(1500, 200); //beep com frequência de 1500Hz e duração de 200ms 
                system("pause"); //pausa a tela
        }
    }while(op!='3'); //fim do-while
}

//Consulta o histórico do carro ---------------------------------------------------------------------------------------------
void consultaHisCar(historico *p){
	FILE *file=NULL;
	char aux[19];
	int i,qtde;
	verificaQtdeHis(&qtde);
	if((file=fopen("Dados/historico.bin","rb"))==NULL){
		printf("\nArquivo Inixistente");
		system("pause"); //pausa a tela
	}	
	else{
		system("cls");//limpa terminal windows
		printf("=======================================");
		printf("\n      Historico de Vendas de Carros");
		printf("\n=======================================\n");
		printf("Digite o CNPJ da concessionária: ");
		gets(aux);
		for(i=0;i<qtde;i++){
			fseek(file,i*sizeof(historico),0);
			fread(p, sizeof(loja),1,file);
			if(strcmp(p->cnpj,aux)==0){
				printf("\nData: %i/%i/%i - Modelo: %s - Cor: %s - Valor: %.2f",p->dataVenda.dia,p->dataVenda.mes,p->dataVenda.ano,p->modelo,p->cor,p->valor);
			} // Exibe os valores armazenados
		}
		printf("\n");
		system("pause");//pausa a tela
		fclose(file); //encerra fluxo
	}
}

//Consulta o histórico da concessionária -------------------------------------------------------------------------
void consultaHisCon(historico *p){
	FILE *file=NULL;
	char aux[20];
	int i,qtde;
	verificaQtdeHis(&qtde);
	if((file=fopen("Dados/historico.bin","rb"))==NULL){
		printf("\nArquivo Inixistente\n");
		system("pause");
	}	
	else{
		system("cls");//limpa terminal windows
		printf("=======================================");
		printf("\n       Historico de Vendas por Modelo");
		printf("\n=======================================\n");
		printf("Digite o Modelo: ");
		gets(aux);
		for(i=0;i<qtde;i++){
			fseek(file,i*sizeof(montadora),0);
			fread(p, sizeof(montadora),1,file);
			if(strcmp(strupr(p->modelo),strupr(aux))==0){
				printf("\nNúmero de Registro: %i - Modelo: %s - Cor: %s - Concessionária: %.2f",p->regcarro,p->modelo,p->cor,p->nome);
			}
		}
		printf("\n\n");
		system("pause");//pausa a tela
		fclose(file); //encerra fluxo
	}
}
//Fim do programa
