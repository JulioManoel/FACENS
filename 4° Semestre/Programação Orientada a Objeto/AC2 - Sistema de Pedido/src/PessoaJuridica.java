import java.util.Scanner;

public class PessoaJuridica extends Cliente implements Clientes{
    private String CNPJ;
    private int prazoFaturamento;
    final private String path = "src/data/clienteJF.txt";

    public void cadastro(String nome, String email) {
        Scanner numInput = new Scanner(System.in);
        Scanner input = new Scanner(System.in);
        System.out.print("Digite o CPNJ: ");
        String cpnj = input.nextLine();
        System.out.print("Digite o prazo máximo de faturamento do pedido: ");
        int prazoFaturamento = numInput.nextInt();
        setNome(nome);
        setEmail(email);
        setCNPJ(documento(cpnj));
        setPrazoFaturamento(prazoFaturamento);
    }

    public String leitura() {
        return Arquivo.Read(path);
    }

    public void print(){
        System.out.println("Nome: " + getNome() + "\tEmail: "+ getEmail() + "\tDocumento: " + getDocumento() + "\tPrazo Faturamento Máximo: " + getPrazoFaturamento());
    }

    public void save(){
        String string = getNome() + ';' + getEmail() + ';' + getDocumento() + ';' + getPrazoFaturamento();
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
                setCNPJ(linha.split(";")[2]);
                setPrazoFaturamento(Integer.parseInt(linha.split(";")[3]));
                return true;
            }
        }
        System.out.println("Documento Invalido");
        return false;
    }

    public String getDocumento() {
        return CNPJ;
    }

    public void setCNPJ(String CNPJ) {
        this.CNPJ = CNPJ;
    }

    public int getPrazoFaturamento() {
        return prazoFaturamento;
    }

    public void setPrazoFaturamento(int prazoFaturamento) {
        this.prazoFaturamento = prazoFaturamento;
    }
}
