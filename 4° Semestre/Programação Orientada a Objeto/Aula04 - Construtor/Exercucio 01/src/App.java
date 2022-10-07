import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        Scanner inputString = new Scanner(System.in);
        Scanner inputInt = new Scanner(System.in);
        System.out.print("Digite seu nome do aluno: ");
        String nome = inputString.nextLine();
        System.out.print("Digite seu endereço: ");
        String endereco = inputString.nextLine();
        System.out.print("Digite sua idade: ");
        int idade = inputInt.nextInt();
        System.out.print("Digite seu sexo: ");
        String sexo = inputString.nextLine();
        System.out.print("Digite seu RG: ");
        int rg = inputInt.nextInt();
        System.out.print("Digite sua curso: ");
        String curso = inputString.nextLine();
        Aluno a1 = new Aluno(nome, endereco, idade, sexo, rg, curso);
        System.out.printf("Aluno %s ", a1.getNome());
        inputString.close();
        inputInt.close();
    }
}
