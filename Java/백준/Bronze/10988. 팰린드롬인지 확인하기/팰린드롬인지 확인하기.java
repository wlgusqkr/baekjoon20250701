import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String iStr, reverseStr;
        boolean bFlag = true;
        iStr = scan.nextLine();

        StringBuffer sb = new StringBuffer(iStr);
        reverseStr = sb.reverse().toString();

        for(int i = 0; i < iStr.length(); i++) {
            if(iStr.charAt(i) != reverseStr.charAt(i)) {
                bFlag = false;
            }
        }

        if(bFlag) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }
        scan.close();
    }
}