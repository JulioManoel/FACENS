import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        int numEstacao, numComando, devastada, pos = 1, permaneceu = 0;
        Scanner input = new Scanner(System.in);

        do{
            System.out.print("Digite o número da Estação (2-100): ");
            numEstacao = input.nextInt();
        }while(numEstacao < 1 && numEstacao > 101);

        do{
            System.out.print("Digite o número de Comandos (1-1000)");
            numComando = input.nextInt();
        }while(numComando < 0 && numComando > 1001);

        System.out.print("Digite o número da Estação devastada: ");
        devastada = input.nextInt();

        input.close();

    }
}