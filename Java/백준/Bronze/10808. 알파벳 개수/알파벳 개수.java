import java.util.Scanner;
import java.util.Vector;

public class Main {
    static int[] a = new int[200];

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String iStr;

        iStr = scan.nextLine();

        for(char c : iStr.toCharArray()) {
            a[(int)c]++;
        }

        for(int i = (int)'a'; i <= (int)'z'; i++) {
            System.out.print(a[i] + " ");
        }



        scan.close();
    }
}