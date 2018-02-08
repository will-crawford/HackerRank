import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static int random ( int n ) { return (int) Math.floor( Math.random() * n ); }

    public static void main(String[] args) {
        System.out.println(5);
        int n = 3 + random( 194 );
        for ( int T = 5; --T >= 0; ) {
            ++n;
            boolean shouldBeCancelled = ( T & 1 ) == 0;
            int k = n - random( n - 2 );
            System.out.println( n + " " + k );
            int a0 = k - n - ( shouldBeCancelled ? 1 : 0 );
            int[] a = new int[n];
            for ( int i = 0, an = a0; i < n; ++i, ++an ) { a[i] = an; }
            for ( int i : a ) { System.out.print( i + " " ); }
            System.out.println();
        }
    }
}
