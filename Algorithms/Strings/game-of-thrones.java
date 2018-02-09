import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner myScan = new Scanner(System.in);
        String inputString = myScan.nextLine();
       
        String ans;
        int[] counts = new int[26]; Arrays.fill(counts, 0);
        for ( char c : inputString.toCharArray() ) { ++counts[ c - 'a' ]; }
        ans = "YES";
        int odds = 0;
        for ( int i : counts ) {
            if ( ( ( i % 2 ) != 0 ) && ( odds++ != 0 ) ) {
                ans = "NO";
                break;
            }
        }
        System.out.println(ans);
        myScan.close();
    }
}
