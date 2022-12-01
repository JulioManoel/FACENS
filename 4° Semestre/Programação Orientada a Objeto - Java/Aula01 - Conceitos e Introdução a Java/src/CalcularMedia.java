import java.util.Scanner;

public class CalcularMedia {
    public static void main(String[] args) throws Exception {
        Scanner entrada = new Scanner(System.in);
        int valor = 0;
        for(int i = 0;i<3;i++){
            System.out.print("Digite o " + (i+1) + "º");
            valor += entrada.nextInt();
        }
        System.out.println("A media dos três numero da " + (valor/3));
        entrada.close();
    }
}
