import java.util.Scanner;

public abstract class Cliente {
    private String nome;
    private String email;

    public static void cadastro() {
        Scanner input = new Scanner(System.in);
        Scanner numInput = new Scanner(System.in);
        Clientes cliente = null;
        int opcao;

        System.out.println("--------- Cadastros de Clientes ---------");
        System.out.print("Digite o nome do cliente: ");
        String nome = input.nextLine();
        System.out.print("Digite o email do cliente: ");
        String email = input.nextLine();
        do{
            System.out.print("Digite [1] para pessoa juridica e [2] para pessoa fisca: ");
            opcao = numInput.nextInt();
            switch(opcao) {
                case 1:
                    cliente = new PessoaJuridica();
                    break;
                case 2:
                    cliente = new PessoaFisica();
                    break;
                default:
                    System.out.println("Opção Invalida");
            }
        } while(opcao != 1 && opcao != 2);
        
        cliente.cadastro(nome, email);
        cliente.save();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String documento(String string) {
        string = string.replace(".", "");
        return string.replace("-", "");
    }
}