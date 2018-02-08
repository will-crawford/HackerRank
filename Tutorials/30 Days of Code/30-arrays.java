import java.io.*;
import java.util.*;


public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        System.err.println(N);
        int[] arr = new int[N];
        for ( int i = N; --i >= 0; ) {
            int tmp = in.nextInt();
            System.err.println(i);
            System.err.println(tmp);
            System.err.flush();
            arr[i] = tmp;
        }
        in.close();
        for ( int i = 0; i < N; ++i ) {
            System.out.print( arr[i] + " " );
        }
        System.out.println();
    }
}
