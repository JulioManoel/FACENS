import java.util.Scanner;

public class CalculaBonificacao {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        System.out.print("Digite o salario que deseja consultar");
        double salario = input.nextDouble();
        if(salario > 1200)
            System.out.println("A bonificação sera de " + 0 + " e o auxilo escola " + 100);
        else{
            if(salario>600)
                System.out.println("A bonificação sera de " + (salario*0.12) + " e o auxilo escola " + 100);
            else{
                if(salario>500)
                    System.out.println("A bonificação sera de " + (salario*0.12) + " e o auxilo escola " + 150);
                else{
                    System.out.println("A bonificação sera de " + (salario*0.5) + " e o auxilo escola " + 150);
                }
            }
        }
        input.close();
    }
}
