import java.time.Year;
import java.util.Scanner;

public class CalculaAniversario {
    public static void main(String[] args) throws Exception{
       Scanner entrada = new Scanner(System.in);
        int anoAtual = Year.now().getValue();
        System.out.print("Digite o ano de nacimento do João: ");
        int anoNacimento = entrada.nextInt();
        System.out.println("João possui atualmente " + (anoAtual-anoNacimento) + "anos");
        System.out.println("João terá em 2024 " + (anoAtual+2-anoNacimento) + "anos");
        entrada.close();    
    }
}
