import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Imovel> imovelList = new ArrayList<>();
        Proprietario[] proprietario = new Proprietario[4];
        proprietario[0] = new Proprietario("111.111.111-11", "Julio Cesar", "(15) 99740-6439");
        proprietario[1] = new Proprietario("222.222.222-22", "Kamilly Manoel", "(15) 9746-5614");
        proprietario[2] = new Proprietario("333.333.333-33", "Giovana Nogueira", "(15) 89415-8463");
        proprietario[3] = new Proprietario("444.444.444-44", "Tamara Aparecida", "(15) 45331-4865");
        
        imovelList.add(new Imovel("Rua Odorico", 1000, 100000, proprietario[0], true));
        imovelList.add(new Imovel("Rua Facens", 100, 220000, proprietario[1], false));
        imovelList.add(new Imovel("Rua Interbairros", 250, 30000, proprietario[2], false));
        imovelList.add(new Imovel("Rua Carolina", 300, 50000, proprietario[3], true));

        int maior = 0;
        Imovel imovelMaior = null;
        for (int i = 0; i < imovelList.size(); i++) {
            if(maior < imovelList.get(i).getMetragem()){
                imovelMaior = imovelList.get(i);
                maior = imovelList.get(i).getMetragem();
            }
        }
        System.out.println("O Endereço do maior imovel: " + imovelMaior.getEndereco());

        double valorMaximo = 2500;
        double valorMinimo = 2000;

        for (Imovel imovel : imovelList) {
            if(imovel.calculaMetragem() >= valorMinimo && imovel.calculaMetragem() <= valorMaximo) {
                System.out.println("Nome do Proprietario: " + imovel.getProprietario().getNome());
                System.out.println("Telefone do Proprietario: " + imovel.getProprietario().getTelefone());
                System.out.println("CPF do Proprietario: " + imovel.getProprietario().getCpf());
                System.out.println("Endereço do Imovel: " + imovel.getEndereco());
                System.out.print("Imovel novo ou Usado: ");
                System.out.println(imovel.isNovo()? "Novo" : "False");
            }
        }
    }
}
