import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        int numEstacao, numComandos, devastada, pos = 1, permaneceu = 0;
        Scanner input = new Scanner(System.in);
        
        do{
            System.out.print("Digite o número de Estações (2-100): ");
            numEstacao = input.nextInt();
        }while(numEstacao < 1 && numEstacao > 101);
        
        do{
            System.out.print("Digite o número de Comandos (1-1000): ");
            numComandos = input.nextInt();
        }while(numComandos < 0 && numComandos > 1001);
        
        System.out.print("Digite o número da Estação de Vastada: ");
        devastada = input.nextInt();

        for(int i=0;i<numComandos;i++){
            if(pos == devastada){
                permaneceu++;
            }
            pos += input.nextInt();
            if(pos > numEstacao){
                pos = 1;
            }
            else if(pos == 0){
                pos = numEstacao;
            }
        }
        
        if(pos == devastada){
            permaneceu++;
        }

        System.out.println("O robô permaneceu " + permaneceu + " vezes");
        input.close();
    }
}