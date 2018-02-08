import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int max = 0;
        while ( n != 0 ) {
            int count = 0;
            while ( n % 2 == 0 )
                n /= 2;
            while ( n % 2 != 0 ) {
                ++count; n /= 2;
            }
            if ( count > max )
                max = count;
        }
        System.out.println (max);
    }
}
