import java.util.Scanner;

public class CalcularCircuferencia {
    public static void main(String[] args) throws Exception {
        Scanner entrada = new Scanner(System.in);
        System.out.print("Digite o raio do Circulo: ");
        int raio = entrada.nextInt();
        System.out.println("A circuferencia é " + (Math.PI*(Math.pow(raio, 2))));
        entrada.close();
    }
}