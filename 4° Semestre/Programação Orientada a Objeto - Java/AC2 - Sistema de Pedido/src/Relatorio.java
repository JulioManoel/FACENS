import java.util.ArrayList;
import java.util.Scanner;

public abstract class Relatorio {
    public static void listaAllClientes() {
        PessoaFisica cliente = new PessoaFisica();
        PessoaJuridica cliente2 = new PessoaJuridica();
        
        System.out.println("--------- Lista Todos os Clientes ---------");
        System.out.println("Clientes Pessoas Fisica:");
        String clientes = cliente.leitura();
        if(!clientes.isEmpty()){
            String linhas[] =  clientes.split("\n");
            for (String linha : linhas) {
                cliente.setNome(linha.split(";")[0]);
                cliente.setEmail(linha.split(";")[1]);
                cliente.setCPF(linha.split(";")[2]);
                cliente.setQtdePacelamento(Integer.parseInt(linha.split(";")[3]));
                cliente.print();
            }
        }
        System.out.println("Clientes Pessoas Juridica:");
        String clientes2 = cliente2.leitura();
        if(!clientes2.isEmpty()){
            String linhas2[] =  clientes2.split("\n");
            for (String linha : linhas2) {
                cliente2.setNome(linha.split(";")[0]);
                cliente2.setEmail(linha.split(";")[1]);
                cliente2.setCNPJ(linha.split(";")[2]);
                cliente2.setPrazoFaturamento(Integer.parseInt(linha.split(";")[3]));
                cliente2.print();
            }
        }
    }

    public static void listaAllFornecedores() {
        Fornecedor fornecedor = new Fornecedor();
        
        System.out.println("--------- Lista Todos os Fornecedores ---------");
        String fornecedores = fornecedor.leitura();
        if(!fornecedores.isEmpty()){
            String linhas[] =  fornecedores.split("\n");
            for (String linha : linhas) {
                fornecedor.setNome(linha.split(";")[0]);
                fornecedor.setCPNJ(linha.split(";")[1]);
                fornecedor.print();
            }
        }
    }

    public static void listaAllProdutos() {
        Produto produto = new Produto();
        
        System.out.println("--------- Lista Todos os Produtos ---------");
        String produtos = produto.leitura();
        if(!produtos.isEmpty()){
            String linhas[] =  produtos.split("\n");
            for (String linha : linhas) {
                produto.setCodigo(linha.split(";")[0]);
                produto.setNome(linha.split(";")[1]);
                produto.setPreco(Double.parseDouble(linha.split(";")[1]));
                produto.print();
            }
        }
    }

    public static void listaAllPedidos() {
        Pedido pedido = new Pedido();
        ArrayList<String> codigoProduto = new ArrayList<>();
        ArrayList<String> qtde = new ArrayList<>();
        
        System.out.println("--------- Lista Todos os Pedidos ---------");
        String pedidos = pedido.leitura();
        
        if(!pedidos.isEmpty()){
            String linhas[] =  pedidos.split("\n");
            for (int i=0; i<linhas.length; i++) {
                pedido = new Pedido();
                String linha = linhas[i];
                pedido.setId(Integer.parseInt(linha.split(";")[0]));
                pedido.setStatus(linha.split(";")[1] == "false" ? false : true);
                pedido.setData(linha.split(";")[2]);
                pedido.setValorTotal(Double.parseDouble(linha.split(";")[3]));
                pedido.setDocumento(linha.split(";")[4]);
                String Lproduto = linha.split(";")[5];
                String linhasProdutos[] = Lproduto.split("/");
                for( String linhaProduto : linhasProdutos ){
                    codigoProduto.add(linhaProduto.split("-")[0]);
                    qtde.add(linhaProduto.split("-")[1]);
                }
                for(int j = 0; j<codigoProduto.size(); j++){
                    Produto produto = new Produto();
                    if(!produto.busca(codigoProduto.get(j))){
                        return;
                    }
                    pedido.addProduto(produto);
                    pedido.addQtde(Integer.parseInt(qtde.get(j)));
                }
                qtde.removeAll(qtde);
                codigoProduto.removeAll(codigoProduto);
                pedido.print();
            }
        }
    }
}
