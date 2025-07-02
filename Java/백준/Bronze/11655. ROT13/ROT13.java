import java.util.Scanner;

public class Main {

    private static void encryt(char c, char firstChar) {
        int tmp = 0;

        tmp = c - firstChar;
        tmp = (tmp + 13) % 26;
        tmp = tmp + firstChar;
        System.out.print((char)tmp);

    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String iStr;
        iStr = scan.nextLine();

        for(char c : iStr.toCharArray()) {
            if(c >= 'a' && c <= 'z') {
                encryt(c, 'a');

            } else if ( c >= 'A' && c <= 'Z') {
                encryt(c, 'A');
            } else {
                System.out.print(c);
            }
        }

        scan.close();
    }
}