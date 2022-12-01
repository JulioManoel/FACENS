/**************************************************/
/*                                                */
/*      Sistema de Venda e Controle de Estoque    */
/*                                                */
/*                  Feito por:                    */
/*     Gustavo Luciano Rossi Teixeira, RA 210333  */
/*       Jo�o Victor Athayde Grilo, RA 210491     */
/*       Julio Cesar Bonow Manoel, RA 210375      */
/*                                                */
/*                                                */
/**************************************************/

#include <stdio.h> //Entrada e Saida
#include <stdlib.h> //System
#include <string.h> //Compara��o de String
#include <locale.h> //Acentua��o

void Menu();
void Pdv();
void Estoque();
void CadastraProdutos();
void EditarProdutos();
void ListarProdutos();
void Vendedor();
void CadastraVendedores();
void ListarVendedores();

void main(){ //fun��o main
	setlocale(LC_ALL, "portuguese"); //set linguagem
	system("title Sistema para Com�rcios"); //t�tulo
	system("mkdir Dados"); //cria pasta
	Menu(); //chama fun��o Menu
}

void Menu(){ //fun��o Menu
	//Variaveis
	char op; //operador de controle char para economizar memoria
	
	do{
		system("cls"); //limpa terminal windows
		printf("=======================================");
		printf("\n                 Menu");
		printf("\n=======================================\n");
		printf("\nDigite o n�mero da sua op��o: \n");
		printf("\n1- Vender Produtos");
		printf("\n2- Estoque");
		printf("\n3- Venderdores");
		printf("\n4- Sair\n");
		op = getch(); //retorna a tecla digitada sem mostra-la
	
		switch (op)
		{
			case '1':
				Pdv(); //fun��o para venda de produtos
				break; //fim case 1
			case '2': 
				Estoque(); //fun��o para menu estoque
				break; //fim case 2
		
            case '3':
                Vendedor(); //fun��o para menu vendedores
                break; //fim case 3
            
			case '4':
				printf("\nFinalizando...\n");
                exit(0); //finaliza programa
                break; //fim case 4
							
			default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms 
                system("pause"); //pausa a tela
        }
    }while(op>'4'); //fim do-while
}

void Pdv(){ //PDV
	//Variaveis
	char nome[30], nomeD[30], produto[100],produtoD[100], op, linha[1000]; 
	char *texto; //cria ponteiro texto
    float preco, vendido, pagar=0;
    int qtd, encontrado=0,i=0,desconto;
	long long int code;
    fpos_t posicaoP,posicaoV; //variavel para marcar a pocis�o do fluxo
    FILE *produtos; //declara um ponteiro produtos
    FILE *vendedores; //declara um ponteiro vendedores
    FILE *venda; //declara um ponteiro venda
    
	vendedores = fopen("Dados/vendedores.txt", "r"); //abre vendedores em modo de leitura
	venda = fopen("Dados/venda.txt", "r"); //abre venda em modo de leitura
	produtos = fopen("Dados/produtos.txt", "r"); //abre produtos em modo de leitura
	system("cls"); //limpar terminal windows
	
	if(produtos!=NULL && vendedores!=NULL){ //caso exista o arquivo produtos e venda ele entra no if
		printf("=======================================");
		printf("\n             Frente de Caixa");
		printf("\n=======================================\n");
		printf("\nDigite o Nome do Vendedor: ");
		fflush(stdin); //limpa buffer do  teclado
		scanf("%s", nomeD);
		strupr(nomeD); //para deixar em maiusculo uma fun��o da biblioteca stdlib
		do{ // l� o arquivo
			if (!strcmp(nome, nomeD)) { // compara com o nome informado se falso retorna 1 ou -1
    		    encontrado = 1; //Caso seja igual ele atribui 1 a encontrado
				break;
   	 		}
			fgetpos(vendedores, &posicaoV); //marca a posi��o do vendedor dentro do arquivo de venda
		}while (fscanf(vendedores, "%s %f", nome, &vendido) != EOF); //final da leitura dos vendedores
		if (encontrado) {
			do{
				system("cls"); //limpar terminal windows
				printf("=======================================");
				printf("\n             Frente de Caixa");
				printf("\n=======================================\n");
				printf("\nVendedor(a): %s - Vendeu: %.2f", nome,vendido);
				printf("\n---------------------------------------");
				if(venda != NULL){ //caso o arquivo venda exista ele entra
					while (!feof(venda)){ //le uma linha
      					fgets(linha, 500, venda);  // o 'fgets' l� at� 499 caracteres ou at� o '\n'
      					if (linha){  //se foi poss�vel ler
							printf("%s\n",linha);
  						}
					}
				}
				printf("\n---------------------------------------\n");	
				printf("Pre�o a Pagar: %.2f", pagar);
				printf("\n---------------------------------------\n");
				printf("\nDigite o n�mero da sua op��o: \n");
				printf("\n1- Adicionar produto a Venda");
				printf("\n2- Desconto");
				printf("\n3- Finalizar Venda\n");
				op = getch();
				
				switch (op){
					case '1':
						printf("\nDigite o nome do produto: ");
						fflush(stdin);
						scanf("%s", produtoD);
						strupr(produtoD); //maiusculo	
						do { // l� o arquivo
							if (!strcmp(produto, produtoD)) { // compara com o nome informado se falso retorna 1 ou -1
    					    encontrado = 1;
							break;
    						}
							fgetpos(produtos, &posicaoP); //marca a posi��o do arquivo Produtos
						}while (fscanf(produtos, "%s %f %d %lld", produto, &preco, &qtd, &code) != EOF); //final da leitura dos produtos
						if(encontrado){
							if(qtd >= 1){ //se quantidade de estoque for maior que 1 entra
								pagar+=preco;
								qtd--;
								i++;
								fclose(produtos);
								produtos = fopen("Dados/produtos.txt", "r+"); //abre produtos como leitura e atualiza��o
								fsetpos(produtos, &posicaoP); //set a posi��o marcada do arquivo produtos
								fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
								fclose(produtos);
								produtos = fopen("Dados/produtos.txt", "r"); //abre produto como leitura
								fclose(venda);
								venda = fopen("Dados/venda.txt", "a"); //abre venda como anexo
								fprintf(venda, "\n%d- %s  Valor: %.2f",i,produto, preco);
								fclose(venda);
								venda = fopen("Dados/venda.txt", "r"); //abre vvenda como leitura
							}
							else{ //caso o estoque seja menor que 1
								Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
								printf("\nProduto sem estoque\n\n ");
								system("pause"); //pausa a tela
							}
						}
						else{ //caso n�o encontr o produto
							Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
							printf("\nProduto n�o encontrado\n\n ");
							system("pause"); //pausa a tela
						}
						encontrado = 0;
						break;//fim case 1 - Adicionar produto
					
					case '2':
						printf("\nDigite o valor do descontro(%%): ");
						scanf("%d",&desconto);
						pagar= pagar-pagar*desconto/100; //conta para efeturar o desconto
            		    break; //fim case 2 - Desconto
						
					case '3':
						vendido+=pagar; //calcula o valor vendido
						fclose(vendedores);//fecha o arquivo vendedores
						vendedores = fopen("Dados/vendedores.txt", "r+"); //abre vendedores como leitura e atualiza��o
						fsetpos(vendedores, &posicaoV); //set a posi��o marcada do arquivo produtos
						fprintf(vendedores, "\n%s %.2f", nome, vendido);
						fclose(produtos);//fecha o arquivo protudos
						fclose(vendedores);//fecha o arquivo vendedores
						fclose(venda); //fecha o arquivo venda
						remove("Dados/venda.txt"); //apaga o arquivo venda
						break;//fim case 3 - Finalizar Venda
					
					default:
           		 	  	Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
						printf("\nOpcao invalida! Tente Novamente!\n\n ");
                		system("pause"); //pausa a tela
				}//switch Estoque
			}while(op!='3');//fim do
		
		}//fim if encontrado vendedor 
		else {
    		Beep(1500, 200); ////beep com frequ�ncia de 1500Hz e dura��o de 200ms
			printf("\nVendedor n�o encontrado ");
    		system("pause"); //pausa a tela
    		Menu();
		}
	}
	else if(produtos==NULL && vendedores==NULL){ //Se n�o tiver produtos ou vendedores
		Beep(1500, 200); ////beep com frequ�ncia de 1500Hz e dura��o de 200ms
		printf("\n N�o tem nenhum vendedor e produto cadastrado\n\n ");
		system("pause"); //pausa a tela
	}
	else if(vendedores==NULL){ //Se n�o tiver vendedores cadastrados
		Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
		printf("\n N�o tem nenhum vendedor cadastrado\n\n ");
		system("pause"); //pausa a tela
	}
	else{ //Se n�o tiver produtos cadastrados
		Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
		printf("\n N�o tem nenhum produto cadastrado\n\n ");
		system("pause"); //pausa a tela
	}
	Menu();
}

void Estoque(){ //Menu Estoque
	char op;
	do{
		system("cls"); //limpar terminal windows
		printf("=======================================");
		printf("\n                 Estoque");
		printf("\n=======================================\n");
		printf("\nDigite o n�mero da sua op��o: \n");
		printf("\n1- Cadastrar Produto");
		printf("\n2- Editar Produtos");
		printf("\n3- Listar Produtos");
		printf("\n4- Voltar\n");
		op = getch();
		system("cls"); //limpar terminal windows
		
		switch (op){
			case '1':
				CadastraProdutos(); //fun��o para cadastro de produtos
				break; //fim case 1
				
			case '2':
				EditarProdutos(); //fun��o para edi��o de produtos
                break; //fim case 2
			
			case '3':
				ListarProdutos(); //fun��o para listagem de produtos
				break; //fim case 3
				
			case '4':
				Menu(); //fun��o para menu principal
				break; //fim case 4
			
			default:
                printf("\nOpcao invalida! Tente Novamente!\n\n");
                Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
                system("pause"); //pausa a tela
		}// fim switch Estoque
	}while(op>'4');//fim do-while
}

void CadastraProdutos(){ //Cadastra Produtos
    //Variaveis
	char produto [100],produtoD [100];
	float preco;
    int qtd, encontrado=0;
	long long int code;
	
	FILE *produtos;
	produtos = fopen("Dados/produtos.txt", "r"); //abre arquivo produtos em modo leitura
	system("cls"); //limpa terminal windows
	printf("=======================================");
	printf("\n          Cadastrar Produto");
	printf("\n=======================================\n\n");
    printf("\n Nome do Produto (Max. 100) e (Sem Espa�o): ");
    fflush(stdin); //limpa buffer do  teclado
	scanf("%s", &produtoD);
   	strupr(produtoD); //converte todos os caracteres para mai�sculo
   	while (fscanf(produtos, " %s %f %d %lld", produto, &preco, &qtd, &code) != EOF){ //l� o arquivo
		if (!strcmp(produto, produtoD)) { // compara com o nome informado se falso retorna 1 ou -1
    	    encontrado = 1;
			break; //fim
    	}
	}
   	if(!encontrado){
		printf("\n Valor do Produto: ");
    	scanf("%f", &preco);
    	printf("\n Quantidade em Estoque: ");
    	scanf("%d", &qtd);
    	printf("\n Codigo do Produto: ");
    	scanf("%lld", &code);
    	fclose(produtos); //fecha arquivo produtos
    	produtos = fopen("Dados/produtos.txt", "a"); //abre arquivo produtos em modo de leitura
		fprintf(produtos, "\n%s %.2f %d %lld", produtoD, preco, qtd, code);
		printf("\nO produto foi cadastrado\n\n");
		system("pause"); //pausa a tela
	}
	else{
		Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
		printf("\nO produto j� existe\n\n");
		system("pause"); //pausa a tela
	}
	fclose(produtos); //fecha arquivo produtos
   	Estoque(); //fun��o para menu estoque
}

void EditarProdutos(){ //Editar Produtos
	//Variaveis
	char produto [100], produtoD [100], op;
	float preco;
    int qtd, i=0,encontrado=0;
	long long int code;
	
	fpos_t posicao; //variavel para marcar a pocis�o do fluxo
	FILE *produtos; //declara um ponteiro produtos 
	produtos = fopen("Dados/produtos.txt", "r"); //abre arquivo produtos em modo de leitura
	system("cls"); //limpa terminal windows
	printf("=======================================");
	printf("\n            Editar Produto");
	printf("\n=======================================\n\n");
	printf("\n Digite o nome do produto: ");
	fflush(stdin); //limpa buffer do  teclado
	scanf("%s", &produtoD);
	strupr(produtoD); //converte todos os caracteres para mai�sculo
	do { // l� o arquivo
		if (!strcmp(produto, produtoD)) { // compara com o nome informado se falso retorna 1 ou -1
    	    encontrado = 1;
			break;
    	}
		fgetpos(produtos, &posicao); //marca a posi��o
	}while (fscanf(produtos, "%s %f %d %lld\n", produto, &preco, &qtd, &code) != EOF);
	if(encontrado){
		do{
			system("cls"); //limpa terminal Windows
			printf("=======================================");
			printf("\n            Editar Produto");
			printf("\n=======================================\n");
			printf("\nProduto Encontrado:");
			printf("\nProduto: %s - Pre�o: %.2f - Estoque: %d - Codigo: %lld",produto,preco,qtd,code);
			printf("\n\nDigite o n�mero da sua op��o: \n");
			printf("\n1- Nome do Produto");
			printf("\n2- Pre�o");
			printf("\n3- Quantidade em Estoque");
			printf("\n4- Codigo do Produto");
			printf("\n5- Voltar\n");
			op = getch(); //retorna a tecla digitada sem mostra-la
			fclose(produtos);
			produtos = fopen("Dados/produtos.txt", "r+"); //abre arquivo produtos em modo de leitura
			fsetpos(produtos, &posicao); //altera posi��o do fluxo
		
			switch(op)
			{
				case '1':
					printf("\nDigite o novo nome (Max. 100) e (Sem Espa�o): ");
					fflush(stdin); //limpa buffer do  teclado
					scanf("%s", &produto);
					strupr(produto); //converte todos os caracteres para mai�sculo
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
				break; //fim case 1
				case '2':
					printf("\nDigite o novo pre�o: ");
					scanf("%f", &preco);
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
					break; //fim case 2
				case '3':
					printf("\nDigite a nova quantidade em estoque: ");
					scanf("%d", &qtd);
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
					break; //fim case 3
				case '4':
					printf("\nDigite o novo codigo do produto: ");
					scanf("%lld", &code);
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
					break; //fim case 4
				case '5':
					break; //fim case 5
				default:	
					printf("\n\nOpcao invalida! Tente Novamente!\n\n");
              	 	system("pause"); //pausa a tela
			}
		}while(op<'5' || op>'5'); //fim menu de edi��o do-while
		}
		else{
			Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
			printf("\n Produto N�o Encontrado\n\n");
			system("pause"); //pause a tela
		}
		fclose(produtos); //fecha arquivo produtos
		Estoque();
}

void ListarProdutos(){ //Listar Produtos
    //Variaveis
	char produto[100];
    float preco;
    int qtd;
	long long int code;
	
	FILE *produtos; //declara um ponteiro produtos
	produtos = fopen("Dados/produtos.txt", "r"); //abre arquivo produtos em modo de leitura
	printf("=======================================");
	printf("\n            Listar Produtos");
	printf("\n=======================================\n\n");
    if(produtos!=NULL){
		while(!feof(produtos)){
        	fscanf(produtos,"%s %f %d %lld", produto, &preco, &qtd, &code);
        	printf(" Produto: %s  -  Pre�o: %.2f - Estoque: %d - Codigo: %lld\n", produto, preco, qtd, code);
    	}
    }
    else{
    	Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms 
		printf("\n N�o tem nenhum produto cadastrado\n");
		system("pause"); //pausa a tela
	}
	printf("\n ");
    system("pause"); //pausa a tela
    fclose(produtos); //fecha arquivo produtos
    Estoque(); //fun��o para menu estoque
}

void Vendedor(){ //Menu Vendedores
	//Variaveis
	char op;
	
	do{
		system("cls"); //limpar terminal windows
		printf("=======================================");
		printf("\n               Vendedores");
		printf("\n=======================================\n");
		printf("\nDigite o n�mero da sua op��o: \n");
		printf("\n1- Cadastrar Vendedor");
		printf("\n2- Listar Vendedor");
		printf("\n3- Voltar\n");
		op = getch(); //retorna a tecla digitada sem mostra-la
		fflush(stdin); //limpa buffer do  teclado
		system("cls"); //limpar terminal windows
		
		switch (op)
		{
			case '1':
				CadastraVendedores(); //fun��o para cadastro de vendedores
				break; //fim case 1
				
			case '2':
				ListarVendedores(); //fun��o listagem de vendedores
                break; //fim case 2
			
			case '3':
				Menu(); //retorna para menu principal
				break; //fim case 3
			
			default:
                printf("\nOpc�o invalida! Tente Novamente!\n\n");
                Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
                system("pause"); //pausa a tela
		}//switch Estoque
	}while(op>3);//fim do
}

void CadastraVendedores(){ //Cadastra Vendedores
    //Variaveis
	char nome [30], nomeD[30];
    int encontrado=0;
    float vendido=0;
    
	FILE *vendedores; //declara um ponteiro vendedores
    vendedores = fopen("Dados/vendedores.txt", "r");
	system("cls"); //limpar terminal windows
	printf("=======================================");
	printf("\n          Cadastrar Vendedor");
	printf("\n=======================================\n\n");
    printf("\n Nome do Vendedor (Max. 30): ");
    fflush(stdin); //limpa buffer do  teclado
	scanf("%s", &nomeD);
   	strupr(nomeD); //converte todos os caracteres para mai�sculo
   	while (fscanf(vendedores, "%s %f", &nome, &vendido) != EOF){ //l� o arquivo
		if (!strcmp(nome, nomeD)) { // compara com o nome informado se falso retorna 1 ou -1
    	    encontrado = 1;
			break;
    	}
	}
   	if(!encontrado){
		printf("\n Vendedor Cadastrado\n\n ");
		fclose(vendedores); //fecha arquivo vendedores
		vendedores = fopen("Dados/vendedores.txt", "a"); //abre o arquivo vendedores em modo de leitura
		fprintf(vendedores, "\n%s %.2f",nomeD, vendido);
		system("pause"); //pausa a tela
	}
	else{
		Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
		printf("\nO vendedor j� existe\n\n ");
		system("pause"); //pausa a tela
	}
	fclose(vendedores); //fecha arquivo vendedores
   	Vendedor(); //fun��o para menu vendedores
}

void ListarVendedores(){ //Listar Vendedores
    //Variaveis
	char nome[30];
    float vendido;
    
	FILE *vendedores; //declara um ponteiro vendedores 
	vendedores = fopen("Dados/vendedores.txt", "r"); //abre o arquivo vendedores em modo de leitura
	printf("=======================================");
	printf("\n            Listar Produtos");
	printf("\n=======================================\n\n");
	if(vendedores != NULL){
    	while(!feof(vendedores)){
    	    fscanf(vendedores,"%s %f", &nome, &vendido);
    	    printf(" Vendedor: %s  -  Vendeu: %.2f\n", nome, vendido);
    	}
    }
    else{
    	Beep(1500, 200); //beep com frequ�ncia de 1500Hz e dura��o de 200ms
		printf("\n N�o tem nenhum vendedor cadastrado\n");
	}
    fclose(vendedores); //fecha o arquivo vendedores
    printf("\n");
    system("pause"); //pausa a tela
    Vendedor(); //fun��o para menu vendedor
}
