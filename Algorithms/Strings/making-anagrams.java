import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        String a = in.nextLine(), b = in.nextLine();
        in.close();
        int[] ac = new int[26], bc = new int[26];
        int d = 0;
        for ( char c : a.toCharArray() ) ++ac[ c - 'a' ];
        for ( char c : b.toCharArray() ) ++bc[ c - 'a' ];
        for ( int i = 0; i < 26; ++i )
            d += Math.abs( bc[i] - ac[i] );
        System.out.println(d);
    }
}
