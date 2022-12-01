import java.util.Scanner;

public class CalculaEnergia {
    public static void main(String[] args) throws Exception {
        int salarioMinimo = 1100;
        float valorQuilowatt = salarioMinimo/500;
        float quilowatt;
        Scanner entrada = new Scanner(System.in);
        System.out.println("Digite a quantidade de quilowatts consumidos: ");
        quilowatt = entrada.nextFloat();
        System.out.println("O valor em reais de cada quilowatt é " + valorQuilowatt);
        System.out.println("O valor em reais a ser pago por essa residência é de " + (valorQuilowatt*quilowatt));
        System.out.println("O valor em reais a ser pago com desconto de 15% é de " + ((valorQuilowatt*quilowatt)*0.85));
        entrada.close();
    }
}
