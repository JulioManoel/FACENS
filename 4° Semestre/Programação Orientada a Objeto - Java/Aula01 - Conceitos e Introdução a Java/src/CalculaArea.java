import java.util.Scanner;

public class CalculaArea {
    public static void main(String[] args) throws Exception{
        Scanner entrada = new Scanner(System.in);
        System.out.print("Digite a area do quadardo: ");
        int area = entrada.nextInt();
        System.out.println("A area do quadrado de " + area + " de lado é " + Math.pow(area, 2));
        
        entrada.close();
    }
}
