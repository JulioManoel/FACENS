import java.io.File;

public class App {
    public static void main(String[] args) {
        File file = new File("src/data");
        if(!file.isDirectory())
            file.mkdir();
        
        Menu.escolha();
    }
}