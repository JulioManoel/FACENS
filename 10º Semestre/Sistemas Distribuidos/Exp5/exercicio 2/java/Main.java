import java.util.Base64;
import demo.PersonProto.Person;

public class Main {
  public static void main(String[] args) {
    try {
        byte[] decoded = Base64.getDecoder().decode(args[0]);
        Person p = Person.parseFrom(decoded);
        System.out.printf("Name: %s\n", p.getName());
        System.out.printf("EnrollNumber: %d\n", p.getEnrollNumber());
        System.out.printf("Height: %.2f\n", p.getHeight());
        System.out.printf("LuckNumbers: %s%n", p.getLuckNumbersList());
    } catch (Exception e) {
        System.out.println(e);
    }
  }
}