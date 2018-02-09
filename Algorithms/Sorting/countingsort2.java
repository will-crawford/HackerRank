import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
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
        for ( int i = 0; i < 100; ++i )
            for ( int j = counts[i]; --j >= 0; )
                System.out.print( i + " " );
        System.out.println();
    }
}
