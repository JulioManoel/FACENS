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
    private int linhaArquivo;

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

    public static void baixaPedido() {
        Scanner input = new Scanner(System.in);
        Scanner numInput = new Scanner(System.in);
        Pedido pedido = new Pedido();
        Clientes cliente;
        int opcao;
        
        System.out.println("--------- Baixa no Pedido ---------");
        System.out.print("Digite o id do pedido: ");
        String id = input.nextLine();
        if(!pedido.busca(id)){
            System.out.println("Erro ao consultar Pedido");
            return;
        }
        if(pedido.getDocumento().length() > 11)
            cliente = new PessoaJuridica();
        else
            cliente = new PessoaFisica();
        if(!cliente.busca(pedido.getDocumento()))
            return;
        pedido.print(cliente);
        do{
            System.out.println("Gostaria de dar baixa neste pedido: [1] Sim ou [2] Não");
            opcao = numInput.nextInt();
        }while(opcao != 1 && opcao != 2);
        if(opcao == 1)
            pedido.setStatus(true);
        pedido.update();        
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

    public String leitura() {
        return Arquivo.Read(path);
    }

    public void print() {
        System.out.print("ID: " + getId() + "\tData: "+ getData() + "\tStatus: ");
        if(isStatus())
            System.out.println("Pago");
        else   
            System.out.println("Pendente");
        System.out.println("Valor Total: " + getValorTotal() + "\tDocumento Cliente: " + getDocumento());
        for(int i=0; i<produtos.size(); i++){
            Produto produto = produtos.get(i);
            System.out.println("Produtos: " + produto.getCodigo() + "\tQtde: " + qtde.get(i));
        }
    }
    
    public void save() {
        String string = Integer.toString(getId()) + ';' + isStatus() + ';' + getData() + ';' + getValorTotal() + ';' + getDocumento() + ';';
        for(int i=0; i<produtos.size(); i++){
            if(i != 0){
                string += '/';
            }
            Produto produto = produtos.get(i);
            string += produto.getCodigo();
            string += '-' + Integer.toString(qtde.get(i));
        }
        Arquivo.Push(path, string);
    }

    public void update(){
        String string = Integer.toString(getId()) + ';' + isStatus() + ';' + getData() + ';' + getValorTotal() + ';' + getDocumento() + ';';
        for(int i=0; i<produtos.size(); i++){
            if(i != 0){
                string += '/';
            }
            Produto produto = produtos.get(i);
            string += produto.getCodigo();
            string += '-' + Integer.toString(qtde.get(i));
        }
        Arquivo.Update(path, string, getLinhaArquivo());
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

    public boolean busca(String id) {
        String texto = Arquivo.Read(path);
        if(texto.isEmpty()){
            System.out.println("Não possui nenhum Pedido cadastrado");
            return false;
        }
        ArrayList<String> codigoProduto = new ArrayList<>();
        ArrayList<String> qtde = new ArrayList<>();
        String linhas[] = texto.split("\n");
        for (int i=0; i<linhas.length; i++) {
            String linha = linhas[i];
            if(linha.indexOf(id) == 0){
                setLinhaArquivo(i);
                setId(Integer.parseInt(linha.split(";")[0]));
                setStatus(linha.split(";")[1] == "false" ? false : true);
                setData(linha.split(";")[2]);
                setValorTotal(Double.parseDouble(linha.split(";")[3]));
                setDocumento(linha.split(";")[4]);
                String Lproduto = linha.split(";")[5];
                String linhasProdutos[] = Lproduto.split("/");
                for( String linhaProduto : linhasProdutos ){
                    codigoProduto.add(linhaProduto.split("-")[0]);
                    qtde.add(linhaProduto.split("-")[1]);
                }
                for(int j = 0; j<codigoProduto.size(); j++){
                    Produto produto = new Produto();
                    if(!produto.busca(codigoProduto.get(j))){
                        return false;
                    }
                    this.produtos.add(produto);
                    this.qtde.add(Integer.parseInt(qtde.get(j)));
                }
                return true;
            }
        }
        System.out.println("Documento Invalido");
        return false;
    }

    public void addProduto(Produto produto) {
        this.produtos.add(produto);
    }

    public void addQtde(int qtde) {
        this.qtde.add(qtde);
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

    public int getLinhaArquivo() {
        return linhaArquivo;
    }

    public void setLinhaArquivo(int linhaArquivo) {
        this.linhaArquivo = linhaArquivo;
    }
}
