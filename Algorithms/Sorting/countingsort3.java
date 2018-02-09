import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        int N = in.nextInt();
        int[] counts = new int[100];
        for ( int i = N; i > 0; --i ) {
            int x = in.nextInt();
            ++counts[x];
            in.nextLine();
        }
        for ( int i = 0, total = 0; i < 100; ++i )
            System.out.print( (total += counts[i]) + " " );
        System.out.println();
    }
}
