import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[][] = new int[6][6];
        for(int i=0; i < 6; i++){
            for(int j=0; j < 6; j++){
                arr[i][j] = in.nextInt();
            }
        }
        int[] offsets[] = {
            { 0, 0 }, { 0, 1 }, { 0, 2 },
                      { 1, 1 },
            { 2, 0 }, { 2, 1 }, { 2, 2 }
        };
        int[] totals = new int[16];
        for ( int x = 0, t = 0; x <= 3; ++x ) {
            for ( int y = 0; y <= 3; ++y ) {
                int total = 0;
                for ( int i = 0; i < 7; ++i ) {
                    total += arr[ x + offsets[i][0] ][ y + offsets[i][1] ];
                }
                totals[t++] = total;
            }
        }
        int maximum = totals[0];
        for ( int t = 1; t < 16; ++t )
            if ( totals[t] > maximum )
                maximum = totals[t];
        System.out.println( maximum );
    }
}
