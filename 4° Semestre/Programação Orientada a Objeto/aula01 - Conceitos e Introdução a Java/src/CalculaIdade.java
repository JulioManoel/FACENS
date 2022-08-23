import java.util.Scanner;

public class CalculaIdade {
    public static void main(String[] args) throws Exception {
        int ano;
        int dataAtual = 2022;
        Scanner entrada = new Scanner(System.in);
        
        System.out.println("Digite o ano de nascimento de João: ");
        ano = entrada.nextInt();
        System.out.println("\nJoão possui " + (dataAtual-ano) + " anos");
        System.out.println("\nJoão terá " + (dataAtual+2-ano) + " anos");
        entrada.close();
    }
}
