import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {

        Scanner input = new Scanner(System.in);
        Scanner inputInt = new Scanner(System.in);
        Aluno a1 = new Aluno();

        System.out.print("Digite o nome: ");
        a1.setNome(input.nextLine());
        System.out.print("Digite o endereço: ");
        a1.setEndereco(input.nextLine());
        System.out.print("Digite a idade: ");
        a1.setIdade(inputInt.nextInt());
        System.out.print("Digite o sexo: ");
        a1.setSexo(input.nextLine());
        System.out.print("Digite o RG: ");
        a1.setRG(inputInt.nextInt());
        System.out.print("Digite o curo: ");
        a1.setCurso(input.nextLine());

        System.out.println("Nome: " + a1.getNome());
        System.out.println("Endereço: " + a1.getEndereco());
        System.out.println("Idade: " + a1.getIdade());
        System.out.println("Sexo: " + a1.getSexo());
        System.out.println("RG: " + a1.getRG());
        System.out.println("Curso: " + a1.getCurso());
        
        inputInt.close();
        input.close();

    }
}
