public class Vinho {
    
    private String nome;
    private String tipo;
    private int anoFabricacao;
    private double preco;
    
    public Vinho(String nome, String tipo, int anoFabricacao, double preco) {
        this.nome = nome;
        this.tipo = tipo;
        this.anoFabricacao = anoFabricacao;
        this.preco = preco;
    }
    
    public String getNome() {
        return nome;
    }
    public double getPreco() {
        return preco;
    }
    public void setPreco(double preco) {
        this.preco = preco;
    }
    public int getAnoFabricacao() {
        return anoFabricacao;
    }
    public void setAnoFabricacao(int anoFabricacao) {
        this.anoFabricacao = anoFabricacao;
    }
    public String getTipo() {
        return tipo;
    }
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
}
