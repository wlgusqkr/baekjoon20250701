import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Map<String, Integer> map = new HashMap<>();
        ArrayList<String> arrList = new ArrayList<>();
        String iStr;
        int n, k;
        n = scan.nextInt();
        k = scan.nextInt();
        for(int i = 0; i < n; i++) {
            iStr = scan.next();
            map.put(iStr, i);
            arrList.add(iStr);
        }
        for(int i = 0; i < k; i++) {
            iStr = scan.next();
            try {
                int num = Integer.parseInt(iStr);
                System.out.println(arrList.get(num-1));
            } catch(Exception e) {
                System.out.println(map.get(iStr) + 1);
            }

        }

        scan.close();
    }
}