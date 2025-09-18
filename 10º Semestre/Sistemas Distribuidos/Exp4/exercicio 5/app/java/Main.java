import demo.PersonProto.Person;
import com.google.protobuf.util.JsonFormat;
import com.google.protobuf.InvalidProtocolBufferException;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        if (args.length == 0) encode();
        else decode(args[0]);
    }

    private static void encode() throws Exception {
        Person p = Person.newBuilder()
                .setName("Angelo Duarte")
                .setEnrollNumber(123456)
                .setHeight(1.77)
                .addAllLuckNumbers(Arrays.asList(7, 23, 47))
                .build();

        String json = JsonFormat.printer().print(p);
        System.out.println(json);
    }

    private static void decode(String json) throws Exception {
        Person.Builder b = Person.newBuilder();
        JsonFormat.parser().ignoringUnknownFields().merge(json, b);
        Person p = b.build();

        System.out.println("Name: " + p.getName());
        System.out.println("EnrollNumber: " + p.getEnrollNumber());
        System.out.println("Height: " + p.getHeight());
        System.out.println("LuckNumbers: " + p.getLuckNumbersList());
    }
}

