import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner (System.in);
        int T = in.nextInt();
        in.nextLine();
        for ( int t = 0; t < T; ++t ) {
            String S = in.nextLine();
            char[] s = S.toCharArray();
            for ( int start = 0; start < 2; ++start ) {
                for ( int i = start; i < s.length; i += 2 )
                    System.out.print( s[i] );
                System.out.print( " " );
            }
            System.out.println();
        }
    }
}
