import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public abstract class Arquivo {
    public static String Read(String path){
        String conteudo = "";
        try {
            FileReader arq = new FileReader(path);
            BufferedReader lerArq = new BufferedReader(arq);
            String linha="";
            try {
                linha = lerArq.readLine();
                while(linha!=null){
                    conteudo += linha+"\n";
                    linha = lerArq.readLine();
                }
                arq.close();
                return conteudo;
            } catch (IOException ex) {
                System.out.println("Erro: Não foi possível ler o arquivo!");
                return "";
            }
        } catch (FileNotFoundException ex) {
            return "";
        }
    }
    
    public static boolean Write(String path, String Texto){
        try {
            FileWriter arq = new FileWriter(path);
            PrintWriter gravarArq = new PrintWriter(arq);
            gravarArq.println(Texto);
            gravarArq.close();
            return true;
        }catch(IOException e){
            System.out.println(e.getMessage());
            return false;
        }
    }

    public static boolean Push(String path, String Texto){
        String conteudo = Read(path);
        if(conteudo.isEmpty())
            return Write(path, Texto);
        else{
            try {
                FileWriter arquivo = new FileWriter(path);
                PrintWriter gravarArq = new PrintWriter(arquivo);
                gravarArq.println(conteudo + Texto);
                gravarArq.close();
                return true;
            }catch(IOException e){
                return false;
            }
        }
    }
    public static boolean Update(String path, String texto, int linha){
        String conteudo = Read(path);
        if(conteudo.isEmpty())
            return false;
        else{
            String linhas[] = conteudo.split("\n");
            linhas[linha] = texto;
            conteudo = "";
            for( String linhaString : linhas){
                conteudo += linhaString + "\n"; 
            }
            try {
                FileWriter arquivo = new FileWriter(path);
                PrintWriter gravarArq = new PrintWriter(arquivo);
                gravarArq.println(conteudo);
                gravarArq.close();
                return true;
            }catch(IOException e){
                return false;
            }
        }
    }
}
