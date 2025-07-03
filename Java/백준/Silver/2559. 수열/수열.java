import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n, k, tmp, max = -10000005;
        int[] psum = new int[1000005];
        int[] arr = new int[1000005];

        n = scan.nextInt();
        k = scan.nextInt();

        for(int i = 1; i <= n; i++) {
            tmp = scan.nextInt();
            psum[i] = psum[i - 1] + tmp;
        }

        for(int i = k; i <= n; i++) {
            tmp = psum[i] - psum[i - k];
            if(tmp > max) {
                max = tmp;
            }
        }
        System.out.println(max);
        scan.close();
    }
}