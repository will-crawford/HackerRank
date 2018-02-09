import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static boolean checkSubGrid ( String[] G, int startRow, int startCol, String[] P, int r, int c ) {
        for ( int patternRow = 0; patternRow < r; ++patternRow ) {
            int gridRow = startRow + patternRow;
            if ( !( G[gridRow].regionMatches(startCol, P[patternRow], 0, c) ) ) {
                return false;
            }
        }
        return true;
    }

    static boolean find ( String[] G, int R, int C, String[] P, int r, int c ) {
        int maxRow = R - r, maxCol = C - c;
        for ( int startRow = 0; startRow <= maxRow; ++startRow ) {
            for ( int startCol = 0; startCol <= maxCol; ++startCol ) {
                if ( checkSubGrid( G, startRow, startCol, P, r, c ) ) { return true; }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int R = in.nextInt();
            int C = in.nextInt();
            String G[] = new String[R];
            for(int G_i=0; G_i < R; G_i++){
                G[G_i] = in.next();
            }
            int r = in.nextInt();
            int c = in.nextInt();
            String P[] = new String[r];
            for(int P_i=0; P_i < r; P_i++){
                P[P_i] = in.next();
            }
            System.out.println( ( find( G, R, C, P, r, c ) ? "YES" : "NO" ) );
        }
    }
}
