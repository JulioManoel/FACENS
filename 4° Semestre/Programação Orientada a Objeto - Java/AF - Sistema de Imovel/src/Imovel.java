public class Imovel {
    private String endereco;
    private int metragem;
    private double valor;
    private Proprietario proprietario;
    private boolean novo;
    
    public Imovel(String endereco, int metragem, double valor, Proprietario proprietario, boolean novo) {
        this.endereco = endereco;
        this.metragem = metragem;
        this.valor = valor;
        this.proprietario = proprietario;
        this.novo = novo;
    }

    public double calculaMetragem() {
        return getValor()/getMetragem();
    }

    public String getEndereco() {
        return endereco;
    }
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public int getMetragem() {
        return metragem;
    }
    public void setMetragem(int metragem) {
        this.metragem = metragem;
    }
    
    public double getValor() {
        return valor;
    }
    public void setValor(double valor) {
        this.valor = valor;
    }
    
    public Proprietario getProprietario() {
        return proprietario;
    }
    public void setProprietario(Proprietario proprietario) {
        this.proprietario = proprietario;
    }
    
    public boolean isNovo() {
        return novo;
    }
    public void setNovo(boolean novo) {
        this.novo = novo;
    }
}
