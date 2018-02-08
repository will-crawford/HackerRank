import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a[] = new int[n];
        for(int a_i=0; a_i < n; a_i++){
            a[a_i] = in.nextInt();
        }

        int totalSwaps = 0;
        for ( int last = n, swaps = 0; --last > 0; totalSwaps += swaps, swaps = 0 ) {
            for ( int i = 0; i < last; ++i ) {
                if ( a[i] > a[i+1] ) {
                    int tmp = a[i]; a[i] = a[i+1]; a[i+1] = tmp;
                    ++swaps;
                }
            }
            if ( swaps == 0 )
                break;
        }
        System.out.println("Array is sorted in " + totalSwaps + " swaps.");
        System.out.println("First Element: " + a[0]);
        System.out.println("Last Element: " + a[n-1]);
    }
}
