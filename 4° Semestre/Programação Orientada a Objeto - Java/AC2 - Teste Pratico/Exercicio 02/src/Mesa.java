public class Mesa {
    private int numMesa;
    private int qtdePessoas;
    private double conta;
    
    public Mesa(int numMesa, int qtdePessoas) {
        this.numMesa = numMesa;
        this.qtdePessoas = qtdePessoas;
        this.conta = 0;
    }

    public int getNumMesa() {
        return numMesa;
    }

    public void setNumMesa(int numMesa) {
        this.numMesa = numMesa;
    }

    public int getQtdePessoas() {
        return qtdePessoas;
    }

    public void setQtdePessoas(int qtdePessoas) {
        this.qtdePessoas = qtdePessoas;
    }

    public double getConta() {
        return conta;
    }

    public void setConta(double conta) {
        this.conta = conta;
    }

    public void pedido(int codigoItem, int qtde) {
        switch (codigoItem){
            case 1:
                this.conta += (2 * qtde);
                break;
            case 2:
                this.conta += (5 * qtde);
                break;
            case 3:
                this.conta += (4 * qtde);
                break;
        }
    }

    public void fechamento(int codigoPagamento) {
        switch (codigoPagamento){
            case 1:
                this.conta += ((this.conta*10)/100);
            case 3:
                this.conta += ((this.conta*5)/100);
        }
    }

    public void calculaPessoa() {
        double aniversariante = (this.conta*56)/100;
        double pessoas = (this.conta - aniversariante)/(qtdePessoas-1);
        System.out.println("O aniversariante irá pagar " + aniversariante);
        System.out.println("O restante da turma irá pagar " + pessoas);
    }

    public void dadosMesa() {
        System.out.println("id: " + this.numMesa + "\tQtde Pessoas: " + this.qtdePessoas + "\tValor da Conta: " + this.conta);
    }

}