import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonSyntaxException;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static class Person {
        public String Name;
        public int EnrollNumber;
        public float Height;
        public List<Integer> LuckNumbers = new ArrayList<>();

        public Person() {}

        public Person(String name, int enrollNumber, float height, List<Integer> luckNumbers) {
            this.Name = name;
            this.enrollNumber = enrollNumber;
            this.Height = height;
            this.LuckNumbers = luckNumbers;
        }
    }

    private static final Gson GSON = new GsonBuilder()
            .disableHtmlEscaping()
            .setPrettyPrinting()
            .create();

    public static void main(String[] args) {
        if (args.length == 0) encode();
        else decode(args[0]);
    }

    private static void encode() {
        Person p = new Person(
            "Angelo Duarte",
            123456,
            1.77,
            List.of(7, 23, 47)
        );
        String json = GSON.toJson(p);
        System.out.println(json);
    }

    private static void decode(String data) {
        Person p = GSON.fromJson(data, Person.class);
        System.out.println("Name: " + p.Name);
        System.out.println("EnrollNumber: " + p.EnrollNumber);
        System.out.println("Height: " + p.Height);
        System.out.println("LuckNumbers: " + p.LuckNumbers);
    }
}