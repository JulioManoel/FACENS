public class App {
    public static void main(String[] args) throws Exception {
        
        Empregado empregado[] = new Empregado[3];
        empregado[0] = new Empregado("José", 200);
        empregado[1] = new Empregado("Maria", 1000);
        empregado[2] = new Empregado("Astoufo", 100);
        
        int posMaior = 0, posMenor = 0;
        
        if(empregado[0].getSalario() > empregado[1].getSalario() && empregado[0].getSalario() > empregado[2].getSalario()) {
            System.out.println("O empregado com maior salario é " + empregado[0].getNome());
            posMaior = 0;
        }
        else if(empregado[1].getSalario() > empregado[2].getSalario())  {
            System.out.println("O empregado com maior salario é " + empregado[1].getNome());
            posMaior = 1;
        }
        else {
            System.out.println("O empregado com maior salario é " + empregado[2].getNome());
            posMaior = 2;
        }

        if(empregado[0].getSalario() < empregado[1].getSalario() && empregado[0].getSalario() < empregado[2].getSalario()) {
            System.out.print("O menor salario é " + empregado[0].getSalario());
            empregado[0].setSalario(((empregado[0].getSalario()*30)/100) + empregado[1].getSalario());
            System.out.println(" e foi para " + empregado[0].getSalario());
            posMenor = 0;
        }
        else if(empregado[1].getSalario() < empregado[2].getSalario()) {
            System.out.print("O menor salario é " + empregado[1].getSalario());
            empregado[1].setSalario(((empregado[1].getSalario()*30)/100) + empregado[1].getSalario());
            System.out.println(" e foi para " + empregado[1].getSalario());
            posMenor = 1;
        }
        else {
            System.out.print("O menor salario é " + empregado[2].getSalario());
            empregado[2].setSalario(((empregado[2].getSalario()*30)/100) + empregado[2].getSalario());
            System.out.println(" e foi para " + empregado[2].getSalario());
            posMenor = 2;
        }

        if(empregado[posMaior].getSalario() >= empregado[posMenor].getSalario())
            System.out.println("O empregado com menor salario não é maior do que com o maior salario");
        else
            System.out.println("O empregado com menor salario é maior do que com o maior salario");
            
    }
}
