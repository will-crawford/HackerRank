import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int k = in.nextInt();
            int maxAB = 0;
            for ( int a = n; --a > 0; ) {
                for ( int b = n; b > a; --b ) {
                    int ab = a & b;
                    if ( ab < k && ab > maxAB ) { maxAB = ab; }
                }
            }
            System.out.println ( maxAB );
        }
    }
}
