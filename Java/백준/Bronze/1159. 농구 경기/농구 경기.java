import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String iStr;
        boolean bFlag = false;
        int[] cnt = new int[30];
        int numberOfPlayers;


        numberOfPlayers = scan.nextInt();

        for(int i = 0 ; i < numberOfPlayers; i++) {
            iStr = scan.next();
            cnt[(int)(iStr.charAt(0) - 'a')]++;
        }

        for(int i = 0 ; i < 30; i++) {
            if(cnt[i] >= 5) {
                bFlag = true;
                System.out.print((char)(i+'a'));
            }
        }
        if(bFlag == false) {
            System.out.print("PREDAJA");
        }

        scan.close();
    }
}