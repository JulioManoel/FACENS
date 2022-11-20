import java.text.DecimalFormat;
import java.time.Instant;
import java.util.ArrayList;
import java.util.Scanner;

public class Pedido {
    private int id;
    private ArrayList<Produto> produtos;
    private ArrayList<Integer> qtde;
    private String data;
    private Double valorTotal;
    private String documento;
    private boolean status;
    final private String path = "src/data/pedido.txt";

    public Pedido() {
        produtos = new ArrayList<>();
        qtde = new ArrayList<>();
        status = false;
        valorTotal = 0.0;
    }

    public static void cadastro() {
        Scanner numInput = new Scanner(System.in);
        Scanner input = new Scanner(System.in);
        Pedido pedido = new Pedido();
        Clientes cliente;
        int opcao = 0;
        Instant instant = Instant.now();
        String data = instant.toString();
        data = data.substring(0, data.indexOf("T"));

        System.out.println("--------- Efetuar Pedido ---------");
        System.out.print("Digite o Documento do Cliente: ");
        String documento = input.nextLine();
        documento = documento.replace(".", "");
        documento = documento.replace("-", "");
        
        if(documento.length() > 11)
            cliente = new PessoaJuridica();
        else 
            cliente = new PessoaFisica();
        if(!cliente.busca(documento)){
            return;
        }
        pedido.setDocumento(documento);
        do{
            Produto produto = new Produto();
            System.out.print("Digite o codigo do produto: ");
            String codigo = input.nextLine();
            if(produto.busca(codigo)){
                pedido.produtos.add(produto);
                System.out.print("Digite a qtde de produto: ");
                int qtde = numInput.nextInt();
                pedido.qtde.add(qtde);
                Double preco = (produto.getPreco()*qtde)+ pedido.getValorTotal();
                pedido.setValorTotal(preco);
            }
            do {
                System.out.println("Gostaria de adiconar outro produto: [1] Sim ou [2] Não ");
                opcao = numInput.nextInt();
            } while(opcao != 1 && opcao != 2);
        }while(opcao == 1 );
        pedido.setData(data);
        pedido.obterId();
        pedido.print(cliente);
        do{
            System.out.print("\nDeseja Cadastrar Pedido: [1] Sim ou [2] Não ");
            opcao = numInput.nextInt();
        }while(opcao != 1 && opcao != 2);
        switch (opcao){
            case 1:
                pedido.save();
            case 2:
                return;
        }
    }

    public void print(Clientes cliente) {
        System.out.println("--------  Pedido  --------");
        System.out.println("Numero do pedido: " + getId() + "\tData: " + getData()) ;
        System.out.println("Valor total do Pedido: " + new DecimalFormat(".##").format(getValorTotal()));
        System.out.println("--------  Cliente  --------");
        System.out.println("Nome: " + cliente.getNome() + "\tDocumento: " + cliente.getDocumento());
        System.out.println("--------  Produtos  --------");
        for(int i=0; i<produtos.size(); i++){
            Produto produto = produtos.get(i);
            System.out.println("Nome:" + produto.getNome() + "\tQtde: " + qtde.get(i) + "\tValor Unit: " + produto.getPreco() + "\tValor Total: " + produto.getPreco()*qtde.get(i));
        }
    }

    public void save() {
        String string = Integer.toString(getId()) + ';' + getData() + ';' + getValorTotal() + ';' + getDocumento() + ';';
        for(int i=0; i<produtos.size(); i++){
            if(i != 0){
                string += '|';
            }
            Produto produto = produtos.get(i);
            string += produto.getCodigo();
            string += '-' + qtde.get(i);
        }
        Arquivo.Push(path, string);
    }

    public void obterId(){
        String string = Arquivo.Read(path);
        if(string.isEmpty()){
            setId(1);
            return;
        }
        String linhas[] = string.split("\n");
        setId(linhas.length+1);
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public Double getValorTotal() {
        return valorTotal;
    }

    public void setValorTotal(Double valorTotal) {
        this.valorTotal = valorTotal;
    }

    public String getDocumento() {
        return documento;
    }

    public void setDocumento(String documento) {
        this.documento = documento;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }
}
