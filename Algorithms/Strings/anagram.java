import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        int T = in.nextInt();
        in.nextLine();
        while ( --T >= 0 ) {
            String s = in.nextLine();
            int l = s.length();
            if ( ( l & 1 ) != 0 ) {
                System.out.println (-1);
            } else {
                int m = l >> 1;
                int[] counts = new int[26]; Arrays.fill (counts, 0);
                for ( char c : s.substring(0, m).toCharArray() ) { ++counts[ c - 'a' ]; }
                for ( char c : s.substring(m, l).toCharArray() ) { --counts[ c - 'a' ]; }
                int changes = 0;
                for ( int i : counts ) { if ( i > 0 ) { changes += i; } }
                System.out.println (changes);
            }
        }
    }
}
