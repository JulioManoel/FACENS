import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        Scanner input = new Scanner(System.in);
        Aluno aluno = new Aluno();
        System.out.print("Digite seu nome: ");
        String name = input.nextLine();
        System.out.print("Digite sua altura: ");
        Double altura = input.nextDouble();
        System.out.print("Digite seu peço: ");
        Double peco = input.nextDouble();
        aluno.set(name, peco, altura);
        aluno.calculaIMC();
        if(aluno.getIMC() < 18.5){
            System.out.print("Anaixo do peso ideal");
        }
        else if(aluno.getIMC() < 24.9){
            System.out.print("Peso Normal");
        }
        else if(aluno.getIMC() < 29.9){
            System.out.print("Acima do peso (sobrepeso)");
        }
        else if(aluno.getIMC() < 34.9){
            System.out.print("Obsidade Grau 1");
        }
        else if(aluno.getIMC() < 39.9){
            System.out.print("Obsidade Grau 2");
        }
        else{
            System.out.print("Obsidade Grau 3");
        }
        input.close();

    }
}
