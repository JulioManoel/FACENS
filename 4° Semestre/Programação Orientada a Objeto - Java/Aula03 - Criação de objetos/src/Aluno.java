public class Aluno {
    
    private String name;
    private Double peco;
    private Double altura;
    private Double IMC;

    public void set(String name, Double peco, Double altura){
        this.name = name;
        this.peco = peco;
        this.altura = altura;
    }
    
    public void calculaIMC(){
        this.IMC = this.peco/Math.pow(this.altura, 2);
    }

    public Double getIMC(){
        return IMC;
    }

}
