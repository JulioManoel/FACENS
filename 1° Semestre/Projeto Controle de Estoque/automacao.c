/**************************************************/
/*                                                */
/*      Sistema de Venda e Controle de Estoque    */
/*                                                */
/*                  Feito por:                    */
/*     Gustavo Luciano Rossi Teixeira, RA 210333  */
/*       João Victor Athayde Grilo, RA 210491     */
/*       Julio Cesar Bonow Manoel, RA 210375      */
/*                                                */
/*                                                */
/**************************************************/


#include <stdio.h> //Entrada e Saida
#include <stdlib.h> //System
#include <string.h> //Comparação de String
#include <locale.h> //Acentuação

void Menu();
void Pdv();
void Estoque();
void CadastraProdutos();
void EditarProdutos();
void ListarProdutos();
void Vendedor();
void CadastraVendedores();
void ListarVendedores();


void main(){ //main
	setlocale(LC_ALL, "portuguese"); //set linguagem
	system("title Sistema para Comercios"); //titulo do programa
	system("mkdir Dados"); //criar pasta
	Menu();
}//main

void Menu(){ //Menu Principal
	char op; //operador de controle char para economizar memoria
	do{
		system("cls"); //limpar terminal windows
		printf("=======================================");
		printf("\n                 Menu");
		printf("\n=======================================\n");
		printf("\nDigite o nï¿½mero da sua opï¿½ï¿½o: \n");
		printf("\n1- Vender Produtos");
		printf("\n2- Estoque");
		printf("\n3- Venderdores");
		printf("\n4- Sair\n");
		op = getch(); //nï¿½o ecoa e nï¿½o nessecita de enter
	
		switch (op)
		{
			case '1':
				Pdv();
				break; //fim case 1 - PDV
			case '2': 
				Estoque();
				break; //fim case 2 - Menu Estoque
		
            case '3':
                Vendedor();
                break; //fim case 3 - Menu Vendedor
            
			case '4':
				printf("\nFinalizando...\n");
                exit(0);
                break; //fim case 4 - Sair
							
			default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                Beep(1500, 200);
                system("pause");
        }
    }while(op>'4');//fim do
} //Menu Principal

void Pdv(){ //PDV
	//Variaveis
	char nome[30], nomeD[30], produto[100],produtoD[100], op, linha[1000];
	char *texto;
    float preco, vendido, pagar=0;
    int qtd, encontrado = 0,i=0,desconto;
	long long int code;
    fpos_t posicaoP,posicaoPI,posicaoV; //variavel para marcar a pocisï¿½o do fluxo
    FILE *produtos; //declara um ponteiro produtos
    FILE *vendedores; //declara um ponteiro vendedores
    FILE *venda; //declara um ponteiro venda
	vendedores = fopen("Dados/vendedores.txt", "r"); //abre vendedores em modo de leitura
	venda = fopen("Dados/venda.txt", "r"); //abre venda em modo de leitura
	produtos = fopen("Dados/produtos.txt", "r"); //abre produtos em modo de leitura
	
	//Comandos
	if(produtos!=NULL && vendedores!=NULL){ //caso exista o arquivo produtos e venda ele entra no if
		system("cls"); //limpar terminal windows
		printf("=======================================");
		printf("\n             Frente de Caixa");
		printf("\n=======================================\n");
		printf("\nDigite o Nome do Vendedor: ");
		fflush(stdin);
		scanf("%s", nomeD);
		strupr(nomeD); //para deixar em maiusculo uma funï¿½ï¿½o da biblioteca stdlib
		do{ // lï¿½ o arquivo
			if (!strcmp(nome, nomeD)) { // compara com o nome informado se falso retorna 1 ou -1
    		    encontrado = 1; //Caso seja igual ele atribui 1 a encontrado
				break;
   	 		}
			fgetpos(vendedores, &posicaoV); //marca a posiï¿½ï¿½o do vendedor dentro do arquivo de venda
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
      					fgets(linha, 500, venda);  // o 'fgets' lï¿½ atï¿½ 499 caracteres ou atï¿½ o '\n'
      					if (texto){  //se foi possï¿½vel ler
							printf("%s\n",linha);
  						}
					}
				}
				printf("\n---------------------------------------\n");	
				printf("Preï¿½o a Pagar: %.2f", pagar);
				printf("\n---------------------------------------\n");
				printf("\nDigite o nï¿½mero da sua opï¿½ï¿½o: \n");
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
						do { // lï¿½ o arquivo
							if (!strcmp(produto, produtoD)) { // compara com o nome informado se falso retorna 1 ou -1
    					    encontrado = 1;
							break;
    						}
							fgetpos(produtos, &posicaoP); //marca a posiï¿½ï¿½o do arquivo Produtos
						}while (fscanf(produtos, "%s %f %d %lld", produto, &preco, &qtd, &code) != EOF); //final da leitura dos produtos
						if(encontrado){
							if(qtd >= 1){ //se quantidade de estoque for maior que 1 entra
								pagar+=preco;
								qtd--;
								i++;
								fclose(produtos);
								produtos = fopen("Dados/produtos.txt", "r+"); //abre produtos como leitura e atualizaï¿½ï¿½o
								fsetpos(produtos, &posicaoP); //set a posiï¿½ï¿½o marcada do arquivo produtos
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
								Beep(1500, 200);
								printf("\nProduto sem estoque\n\n ");
								system("pause");
							}
						}
						else{ //caso nï¿½o encontr o produto
							Beep(1500, 200);
							printf("\nProduto nï¿½o encontrado\n\n ");
							system("pause");
						}
						encontrado = 0;
						break;//fim case 1 - Adicionar produto
					
					case '2':
						printf("\nDigite o valor do descontro(%%): ");
						scanf("%d",&desconto);
						pagar= pagar-pagar*desconto/100;
            		    break;//fim case 2 - Desconto
						
					case '3':
						vendido+=pagar;
						printf("\n%.2f\n",vendido);
						system("pause");
						fclose(vendedores);
						vendedores = fopen("Dados/vendedores.txt", "r+"); //abre vendedores como leitura e atualizaï¿½ï¿½o
						fsetpos(vendedores, &posicaoV); //set a posiï¿½ï¿½o marcada do arquivo produtos
						fprintf(vendedores, "\n%s %.2f", nome, vendido);
						fclose(produtos);
						fclose(vendedores);//fecha o arquivo vendedores
						fclose(venda); //fecha o arquivo venda
						remove("Dados/venda.txt"); //apaga o arquivo venda
						break;//fim case 3 - Finalizar Venda
					
					default:
           		 	  	Beep(1500, 200);
						printf("\nOpcao invalida! Tente Novamente!\n\n ");
                		system("pause");
				}//switch Estoque
			}while(op!='3');//fim do
		
		}//fim if encontrado vendedor 
		else {
    		Beep(1500, 200);
			printf("\nVendedor nï¿½o encontrado ");
    		system("pause");
    		Menu();
		}
	}
	else if(produtos==NULL && vendedores==NULL){
		Beep(1500, 200);
		printf("\n Nï¿½o tem nenhum vendedor e produto cadastrado\n\n ");
		system("pause");
	}
	else if(vendedores==NULL){
		Beep(1500, 200);
		printf("\n Nï¿½o tem nenhum vendedor cadastrado\n\n ");
		system("pause");
	}
	else{
		Beep(1500, 200);
		printf("\n Nï¿½o tem nenhum produto cadastrado\n\n ");
		system("pause");
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
		printf("\nDigite o nï¿½mero da sua opï¿½ï¿½o: \n");
		printf("\n1- Cadastrar Produto");
		printf("\n2- Editar Produtos");
		printf("\n3- Listar Produtos");
		printf("\n4- Voltar\n");
		op = getch();
		system("cls"); //limpar terminal windows
		
		switch (op){
			case '1':
				CadastraProdutos();
				break;
				
			case '2':
				EditarProdutos();
                break;
			
			case '3':
				ListarProdutos();
				break;
				
			case '4':
				Menu();
				break;
			
			default:
                printf("\nOpcao invalida! Tente Novamente!\n\n");
                Beep(1500, 200);
                system("pause");
		}//switch Estoque
	}while(op>'4');//fim do
}

void CadastraProdutos(){ //Cadastra Produtos
    //Variaveis
	char produto [100],produtoD [100];
	float preco;
    int qtd, encontrado=0;
	long long int code;
	FILE *produtos;
	produtos = fopen("Dados/produtos.txt", "r");
	system("cls");
	printf("=======================================");
	printf("\n          Cadastrar Produto");
	printf("\n=======================================\n\n");
    printf("\n Nome do Produto (Max. 100) e (Sem Espaï¿½o): ");
    fflush(stdin);
	scanf("%s", &produtoD);
   	strupr(produtoD);
   	while (fscanf(produtos, " %s %f %d %lld", &produto, &preco, &qtd, &code) != EOF){ //lï¿½ o arquivo
		if (!strcmp(produto, produtoD)) { // compara com o nome informado se falso retorna 1 ou -1
    	    encontrado = 1;
			break;
    	}
	}
   	if(!encontrado){
		printf("\n Valor do Produto: ");
    	scanf("%f", &preco);
    	printf("\n Quantidade em Estoque: ");
    	scanf("%d", &qtd);
    	printf("\n Codigo do Produto: ");
    	scanf("%lld", &code);
    	fclose(produtos);
    	produtos = fopen("Dados/produtos.txt", "a");
		fprintf(produtos, "\n%s %.2f %d %lld", produtoD, preco, qtd, code);
		printf("\nO produto foi cadastrado\n\n");
		system("pause");
	}
	else{
		Beep(1500, 200);
		printf("\nO produto jï¿½ existe\n\n");
		system("pause");
	}
	fclose(produtos);
   	Estoque();
}

void EditarProdutos(){ //Editar Protudos
	char produto [100], produtoD [100], op;
	float preco;
    int qtd, i=0,encontrado=0;
	long long int code;
	fpos_t posicao; //variavel para marcar a pocisï¿½o do fluxo
	FILE *produtos;
	produtos = fopen("Dados/produtos.txt", "r");
	system("cls");
	printf("=======================================");
	printf("\n            Editar Produto");
	printf("\n=======================================\n\n");
	printf("\n Digite o nome do produto: ");
	fflush(stdin);
	scanf("%s", &produtoD);
	strupr(produtoD);
	do { // lï¿½ o arquivo
		if (!strcmp(produto, produtoD)) { // compara com o nome informado se falso retorna 1 ou -1
    	    encontrado = 1;
			break;
    	}
		fgetpos(produtos, &posicao); //marca a posiï¿½ï¿½o
	}while (fscanf(produtos, "%s %f %d %lld\n", &produto, &preco, &qtd, &code) != EOF);
	if(encontrado){
		do{
			system("cls");
			printf("=======================================");
			printf("\n            Editar Produto");
			printf("\n=======================================\n");
			printf("\nProduto Encontrado:");
			printf("\nProduto: %s - Preï¿½o: %.2f - Estoque: %d - Codigo: %lld",produto,preco,qtd,code);
			printf("\n\nDigite o nï¿½mero da sua opï¿½ï¿½o: \n");
			printf("\n1- Nome do Produto");
			printf("\n2- Preï¿½o");
			printf("\n3- Quantidade em Estoque");
			printf("\n4- Codigo do Produto");
			printf("\n5- Voltar\n");
			op = getch();
			produtos = fopen("Dados/produtos.txt", "r+");
			fsetpos(produtos, &posicao);
		
			switch(op)
			{
				case '1':
					printf("\nDigite o novo nome (Max. 100) e (Sem Espaï¿½o): ");
					fflush(stdin);
					scanf("%s", &produto);
					strupr(produto);
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
				break;
				case '2':
					printf("\nDigite o novo preï¿½o: ");
					scanf("%f", &preco);
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
					break;
				case '3':
					printf("\nDigite a nova quantidade em estoque: ");
					scanf("%d", &qtd);
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
					break;
				case '4':
					printf("\nDigite o novo codigo do produto: ");
					scanf("%lld", &code);
					fprintf(produtos, "\n%s %.2f %d %lld", produto, preco, qtd, code);
					break;
				case '5':
					fclose(produtos);
					Estoque();
					break;
				default:	
					printf("\n\nOpcao invalida! Tente Novamente!\n\n");
              	 	system("pause");
			}
		}while(op<'5' || op>'5');
		}//fim if Editar Produto
		else{
			Beep(1500, 200);
			printf("\n Produto Nï¿½o Encontrado\n\n");
			system("pause");
			Estoque();
		}
}

void ListarProdutos(){ //Listar Produtos
    char produto[100];
    float preco;
    int qtd;
	long long int code;
	FILE *produtos;
	produtos = fopen("Dados/produtos.txt", "r");
	printf("=======================================");
	printf("\n            Listar Produtos");
	printf("\n=======================================\n\n");
    if(produtos!=NULL){
		while(!feof(produtos)){
        	fscanf(produtos,"%s %f %d %lld", &produto, &preco, &qtd, &code);
        	printf(" Produto: %s  -  Preï¿½o: %.2f - Estoque: %d - Codigo: %lld\n", produto, preco, qtd, code);
    	}
    }
    else{
    	Beep(1500, 200);
		printf("\n Nï¿½o tem nenhum produto cadastrado\n");
		system("pause");
	}
	printf("\n ");
    system("pause");
    fclose(produtos);
    Estoque();
}

void Vendedor(){ //Menu Vendedores
	char op;
	do{
		system("cls"); //limpar terminal windows
		printf("=======================================");
		printf("\n               Vendedores");
		printf("\n=======================================\n");
		printf("\nDigite o nï¿½mero da sua opï¿½ï¿½o: \n");
		printf("\n1- Cadastrar Vendedor");
		printf("\n2- Listar Vendedor");
		printf("\n3- Voltar\n");
		op = getch();
		fflush(stdin);
		system("cls"); //limpar terminal windows
		
		switch (op)
		{
			case '1':
				CadastraVendedores();
				break;
				
			case '2':
				ListarVendedores();
                break;
			
			case '3':
				Menu();
				break;
			
			default:
                printf("\nOpcï¿½o invalida! Tente Novamente!\n\n");
                Beep(1500, 200);
                system("pause");
		}//switch Estoque
	}while(op>3);//fim do
}

void CadastraVendedores(){ //Cadastra Vendedores
    //Variaveis
	char nome [30], nomeD[30];
    int encontrado=0;
    float vendido=0;
	FILE *vendedores;
    vendedores = fopen("Dados/vendedores.txt", "r");
	system("cls");
	printf("=======================================");
	printf("\n          Cadastrar Vendedor");
	printf("\n=======================================\n\n");
    printf("\n Nome do Vendedor (Max. 30): ");
    fflush(stdin);
	scanf("%s", &nomeD);
   	strupr(nomeD);
   	while (fscanf(vendedores, "%s %f", &nome, &vendido) != EOF){ //lï¿½ o arquivo
		if (!strcmp(nome, nomeD)) { // compara com o nome informado se falso retorna 1 ou -1
    	    encontrado = 1;
			break;
    	}
	}
   	if(!encontrado){
		printf("\n Vendedor Cadastrado\n\n ");
		fclose(vendedores);
		vendedores = fopen("Dados/vendedores.txt", "a");
		fprintf(vendedores, "\n%s %.2f",nomeD, vendido);
		system("pause");
	}
	else{
		Beep(1500, 200);
		printf("\nO vendedor jï¿½ existe\n\n ");
		system("pause");
	}
	fclose(vendedores);
   	Vendedor();
}

void ListarVendedores(){ //Listar Vendedores
    char nome[30];
    float vendido;
	FILE *vendedores;
	vendedores = fopen("Dados/vendedores.txt", "r");
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
    	Beep(1500, 200);
		printf("\n NÃ£o tem nenhum vendedor cadastrado\n");
	}
    fclose(vendedores);
    printf("\n");
    system("pause");
    Vendedor();
}
