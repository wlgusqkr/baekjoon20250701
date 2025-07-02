import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Vector<String> resultVec = new Vector<String>();
        String iRegEx, regPrefix, regSuffix, iStr, iStrPrefix, iStrSuffix;
        int cnt, starIndex;

        cnt = scan.nextInt();
        iRegEx = scan.next();

        starIndex = iRegEx.indexOf("*");
        regPrefix = iRegEx.substring(0, starIndex);
        regSuffix = iRegEx.substring(starIndex+1);

        for(int i = 0 ; i < cnt; i++) {
            iStr = scan.next();

            if((regPrefix.length() + regSuffix.length()) > iStr.length()) {
                resultVec.add("NE");
                continue;
            }
            
            iStrPrefix = iStr.substring(0, starIndex);
            iStrSuffix = iStr.substring(iStr.length() - regSuffix.length());

            if(regPrefix.equals(iStrPrefix) && regSuffix.equals(iStrSuffix)) {
                resultVec.add("DA");
            } else {
                resultVec.add("NE");
            }
        }

        for( String result : resultVec) {
            System.out.println(result);
        }


        scan.close();
    }
}