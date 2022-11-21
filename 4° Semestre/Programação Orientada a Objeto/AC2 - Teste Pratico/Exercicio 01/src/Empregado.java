public class Empregado {
    private String nome;
    private double salario;
    
    public Empregado(String nome, double salario) {
        this.nome = nome;
        if(salario <= 0)
            this.salario = 0;
        else
            this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        if(salario <= 0)
            this.salario = 0;
        else
            this.salario = salario;
    }

    public double salarioLiquido(double desconto) {
        return this.salario - desconto;
    }
}