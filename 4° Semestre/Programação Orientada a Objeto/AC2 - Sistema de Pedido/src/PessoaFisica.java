import java.util.Scanner;

public class PessoaFisica extends Cliente implements Clientes{
    private String CPF;
    private int qtdePacelamento;
    final private String path = "src/data/clientePF.txt";

    public void cadastro(String nome, String email){
        Scanner numInput = new Scanner(System.in);
        Scanner input = new Scanner(System.in);
        System.out.print("Digite o CPF: ");
        String cpf = input.nextLine();
        System.out.print("Digite a quantidade máximo de parcelamento do pedido: ");
        int qtdePacelamento = numInput.nextInt();
        setNome(nome);
        setEmail(email);
        setCPF(documento(cpf));
        setQtdePacelamento(qtdePacelamento);
    }

    public String leitura() {
        return Arquivo.Read(path);
    }

    public void print() {
        System.out.println("Nome: " + getNome() + "\tEmail: "+ getEmail() + "\tDocumento: " + getDocumento() + "\tParcelamento Máximo: " + getQtdePacelamento());
    }

    public void save() {
        String string = getNome() + ';' + getEmail() + ';' + getDocumento() + ';' + getQtdePacelamento();
        Arquivo.Push(path, string);
    }

    public boolean busca(String documento) {
        String texto = Arquivo.Read(path);
        if(texto.isEmpty()){
            System.out.println("Não possui nenhum Cliente cadastrado");
            return false;
        }
        String linhas[] = texto.split("\n");
        for (String linha : linhas) {
            if(linha.indexOf(documento) >= 0){
                setNome(linha.split(";")[0]);
                setEmail(linha.split(";")[1]);
                setCPF(linha.split(";")[2]);
                setQtdePacelamento(Integer.parseInt(linha.split(";")[3]));
                return true;
            }
        }
        System.out.println("Documento Invalido");
        return false;
    }
    
    public String getDocumento() {
        return CPF;
    }
    public void setCPF(String CPF) {
        this.CPF = CPF;
    }
    public int getQtdePacelamento() {
        return qtdePacelamento;
    }
    public void setQtdePacelamento(int qtdePacelamento) {
        this.qtdePacelamento = qtdePacelamento;
    }
}
