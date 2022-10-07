import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        
        Scanner input = new Scanner(System.in);
        Ponto p[] = new Ponto[2];
        int x,y;
        for(int i=0;i<2;i++){
            System.out.print("Digite o ponto x" + (i+1) + ": ");
            x = input.nextInt();
            System.out.print("Digite o ponto y" + (i+1) + ": ");
            y = input.nextInt();
            p[i] = new Ponto(x, y); 
        }
        System.out.println("O valor é " + p[0].caculaDistancia(p[1]));
        input.close();

    }
}
