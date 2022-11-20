import java.util.Scanner;

public class Fornecedor {
    private String nome;
    private String CPNJ;
    final private String path = "src/data/fornecedor.txt";

    public static void cadastro(){
        Scanner input = new Scanner(System.in);
        Fornecedor fornecedor = new Fornecedor();

        System.out.println("--------- Cadastros de Fornecedor ---------");
        System.out.print("Digite o nome do fornecedor: ");
        String nome = input.nextLine();
        System.out.print("Digite o CPNJ do fornecedor: ");
        String cnpj = input.nextLine();
        cnpj = cnpj.replace(".", "");
        cnpj = cnpj.replace("-", "");
        
        fornecedor.setNome(nome);
        fornecedor.setCPNJ(cnpj);
        fornecedor.save();
    }

    public void save() {
        String string = getNome() + ';' + getCPNJ();
        Arquivo.Push(path, string);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCPNJ() {
        return CPNJ;
    }

    public void setCPNJ(String CPNJ) {
        this.CPNJ = CPNJ;
    }
}
