public class App {
    public static void main(String[] args) throws Exception {
        
        Mesa mesa1 = new Mesa(1, 2);
        Mesa mesa2 = new Mesa(2, 10);

        mesa1.dadosMesa();
        mesa2.dadosMesa();

        mesa1.pedido(1, 5);
        mesa1.pedido(3, 10);
        mesa2.pedido(2, 9);
        mesa2.pedido(3, 7);
        
        mesa1.calculaPessoa();
        mesa2.calculaPessoa();

        System.out.println("A mesa com maior conta é:");
        if(mesa1.getConta() > mesa2.getConta())
            mesa1.dadosMesa();
        else
            mesa2.dadosMesa();

    }
}
