import java.util.Scanner;

public class Menu {
    
    public static void print(){
        System.out.println("\n--------- Sistema de Pedidos ---------");
        System.out.println("Escolha uma das opções a Seguir:");
        System.out.println("1. Cadastros de Clientes");
        System.out.println("2. Cadastro de Fornecedores");
        System.out.println("3. Cadastro de Produtos");
        System.out.println("4. Efetuação De um Pedido");
        System.out.println("5. Baixa de Pagamento de um Pedido");
        System.out.println("6. Relatórios");
        System.out.println("7. Sair (terminal)\n");
    }

    public static void escolha() {
        int opcao;
        Scanner input = new Scanner(System.in);
        
        do{
            print();
            opcao = input.nextInt();
            switch(opcao) {
                case 1:
                    Cliente.cadastro();
                    break;
                case 2:
                    Fornecedor.cadastro();
                    break;
                case 3:
                    Produto.cadastro();
                    break;
                case 4:
                    Pedido.cadastro();
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                default:
                    System.out.println("Opção Invalida");
            }
        }while(opcao != 7);
    }
}
