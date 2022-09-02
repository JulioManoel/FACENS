import java.util.Scanner;

public class ListaCargos {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        String[] cargo = {"Escriturário", "Secretário", "Caixa", "Gerente", "Diretor"};
        int[] aumento = {50,35,20,10,0};
        
        for(int i=0;i<5;i++){
            System.out.println("[" + (i+1) + "] " + cargo[0] + "\n");
        }
        System.out.print("Digite o codigo que deseja consultar: ");
        int codigo = input.nextInt();
        System.out.print("Digite o seu salario deseja consultar: ");
        double salario = input.nextDouble();
        System.out.println("Cargo: " + cargo[codigo-1] + " - Novo Salario: " + (((salario * aumento[codigo-1])/100)+salario));
        input.close();
    }
}
