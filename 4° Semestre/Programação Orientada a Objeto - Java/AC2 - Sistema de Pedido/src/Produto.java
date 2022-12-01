import java.util.Scanner;

public class Produto {
    private String codigo;
    private String nome;
    private Double preco;
    final private String path = "src/data/produto.txt";

    public static void cadastro() {
        Scanner numInput = new Scanner(System.in);
        Scanner input = new Scanner(System.in);
        Produto produto = new Produto();
        
        System.out.println("--------- Cadastros de Produto ---------");
        System.out.print("Digite o nome do produto: ");
        String nome = input.nextLine();
        System.out.print("Digite o codigo do produto: ");
        String codigo = input.nextLine();
        System.out.print("Digite o preço do produto: ");
        double preco = numInput.nextDouble();
        produto.setNome(nome);
        produto.setCodigo(codigo);
        produto.setPreco(preco);
        produto.save();
    }

    public String leitura() {
        return Arquivo.Read(path);
    }

    public void print() {
        System.out.println("Codigo: " + getCodigo() + "\tNome: "+ getNome() + "\tPreço: " + getPreco());
    }

    public void save() {
        String string = getCodigo() + ';' + getNome() + ';' + getPreco();
        Arquivo.Push(path, string);
    }

    public boolean busca(String codigo) {
        String texto = Arquivo.Read(path);
        if(texto.isEmpty()){
            System.out.println("Não possui nenhum Produto cadastrado");
            return false;
        }
        String linhas[] = texto.split("\n");
        for (String linha : linhas) {
            if(linha.indexOf(codigo) == 0){
                setCodigo(linha.split(";")[0]);
                setNome(linha.split(";")[1]);
                setPreco(Double.parseDouble(linha.split(";")[2]));
                return true;
            }
        }
        return false;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public Double getPreco() {
        return preco;
    }
    public void setPreco(Double preco) {
        this.preco = preco;
    }
}
