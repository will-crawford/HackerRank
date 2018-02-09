import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner (System.in);
        int n = scanner.nextInt();
        int[] counts = new int[100];
        for ( int i = 0; i < 100; ++i )
            counts[i] = 0;
        for ( int i = 0; i < n; ++i ) {
            int x = scanner.nextInt();
            ++counts[x];
        }
        scanner.close();
        for ( int i = 0; i < 100; ++i ) System.out.print( counts[i] + " " );
        System.out.println();
    }
}
