import java.util.Scanner;

public class MaiorData {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        int[] dia = new int[2];
        int[] mes = new int[2];
        int[] ano = new int[2];

        for(int i=0;i<2;i++){
            System.out.print("Digite o dia da " + (i+1) + "º data: ");
            dia[i] = input.nextInt();
            System.out.print("Digite o mês da " + (i+1) + "º data: ");
            mes[i] = input.nextInt();
            System.out.print("Digite o ano da " + (i+1) + "º data: ");
            ano[i] = input.nextInt();
        }
        
        if(ano[0] == ano[1]){
            if(mes[0] == mes[1]){
                if(dia[0] > dia[1])
                    System.out.println("A maior data é a " + dia[0] + "/" + mes[0] + "/" + ano[0]);
                else
                    System.out.println("A maior data é a " + dia[1] + "/" + mes[1] + "/" + ano[1]);
            }
            else{
                if(mes[0] > mes[1])
                    System.out.println("A maior data é a " + dia[0] + "/" + mes[0] + "/" + ano[0]);
                else
                    System.out.println("A maior data é a " + dia[1] + "/" + mes[1] + "/" + ano[1]);
            }
        }
        else{
            if(ano[0] > ano[1])
                System.out.println("A maior data é a " + dia[0] + "/" + mes[0] + "/" + ano[0]);
            else
                System.out.println("A maior data é a " + dia[1] + "/" + mes[1] + "/" + ano[1]);
        }
        input.close();
    }
}
