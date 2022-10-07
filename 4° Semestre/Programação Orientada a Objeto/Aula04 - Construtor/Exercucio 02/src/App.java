import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        Vinho v1 = executaLeitura();
        Vinho v2 = executaLeitura();
        Vinho v3 = executaLeitura();
        Vinho vinhoVelho;

        if(v1.getPreco() > v2.getPreco() && v1.getPreco() > v3.getPreco()){
            System.out.print("Vinho mais caro é o " + v1.getNome());
        }
        else if(v2.getPreco() > v3.getPreco()){
            System.out.print("Vinho mais caro é o " + v2.getNome());
        }
        else{
            System.out.print("Vinho mais caro é o " + v3.getNome());
        }
        System.out.print("Vinho mais velho: ");
        if(v1.getAnoFabricacao()>v2.getAnoFabricacao() && v1.getAnoFabricacao() > v3.getAnoFabricacao()){
            vinhoVelho = v1;
        }
        else if(v2.getPreco() > v3.getPreco()){
            vinhoVelho = v2;
        }
        else{
            vinhoVelho = v3;
        }
        

        
    }

    public static Vinho executaLeitura(){
        Scanner inputString = new Scanner(System.in);
        Scanner inputInt = new Scanner(System.in);
        System.out.print("Digite o nome do vinho: ");
        String nome = inputString.nextLine();
        System.out.print("Digite o tipo do vinho: ");
        String tipo = inputString.nextLine();
        System.out.print("Digite o ano de fabricação do vinho: ");
        int anoFabricacao = inputInt.nextInt();
        System.out.print("Digite o preço do vinho: ");
        double preco = inputInt.nextDouble();
        inputInt.close();
        inputString.close();

        Vinho vinho = new Vinho(nome, tipo, anoFabricacao, preco);
        return vinho;
    }
}
