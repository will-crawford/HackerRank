import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static long factorial ( long n ) {
        return n > 1 ? factorial ( n - 1 ) * n : 1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner ( System.in );
        int N = in.nextInt();
        in.close();
        System.out.println( factorial (N) );
    }
}
