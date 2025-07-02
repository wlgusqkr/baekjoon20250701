import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String iStr;
        iStr = scan.nextLine();

        iStr.chars().map(x -> {
            if(x >= 'a' && x <= 'z') {
                return ((x - 'a' + 13) % 26 + 'a');
            } else if(x >= 'A' && x <= 'Z') {
                return ((x - 'A' + 13) % 26 + 'A');
            } else {
                return x;
            }
        }).forEach(x -> System.out.print((char)x));

        scan.close();
    }
}
