public class Aluno {

    private String nome;
    private String endereco;
    private int idade;
    private String sexo;
    private int rg;
    private String curso;

    public Aluno(String nome, String enderco, int idade, String sexo, int rg, String curso) {
        this.nome = nome;
        this.endereco = enderco;
        this.idade = idade;
        this.sexo = sexo;
        this.rg = rg;
        this.curso = curso;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public int getRg() {
        return rg;
    }

    public void setRg(int rg) {
        this.rg = rg;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getEnderco() {
        return endereco;
    }

    public void setEnderco(String enderco) {
        this.endereco = enderco;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    
    
}
