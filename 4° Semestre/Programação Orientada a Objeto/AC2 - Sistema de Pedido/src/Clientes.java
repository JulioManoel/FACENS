public interface Clientes{
    void cadastro(String nome, String email);
    void save();
    boolean busca(String documento);
    String getNome();
    String getDocumento();
    String leitura();
    void print();
}