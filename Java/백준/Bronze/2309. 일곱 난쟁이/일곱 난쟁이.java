import java.util.Scanner;
import java.util.Vector;

public class Main {
    static int n = 9, k = 2;
    static Vector<Integer> resultVector = new Vector<Integer>();

    private static void print(Vector<Integer> vector) {
        vector.stream().sorted().forEach(System.out::println);
    }

    private static void combi(int start, Vector<Integer> vector) {
        if(resultVector.size() == 7) {
            int sum = resultVector.stream().mapToInt(Integer::intValue).sum();
            if(sum == 100) {
                print(resultVector);
                System.exit(0);
            }
            return;
        }
        for(int i = start + 1; i < n; i++) {
            resultVector.add(vector.get(i));
            combi(i, vector);
            resultVector.remove(resultVector.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Vector<Integer> b = new Vector<>();
        for(int i = 0 ; i < 9; i++) {
            b.add(scan.nextInt());
        }

        combi(-1, b);
        scan.close();

    }
}