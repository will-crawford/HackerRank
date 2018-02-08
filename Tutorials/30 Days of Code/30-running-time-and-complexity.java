import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static int[] primes;
    private static int hwm, nextCandidate, delta;
    static boolean isPrime (int n) {
        if ( n < 2 )
            return false;
        int limit = (int) Math.floor( Math.sqrt(n) );
        for ( int i = 0; ; ++i ) {
            while ( i >= hwm ) {
                do {
                    nextCandidate += delta;
                    delta = 6 - delta;
                } while ( ! isPrime(nextCandidate) );
                primes[hwm++] = nextCandidate;
            }
            if ( primes[i] > limit )
                break;
            if ( n % primes[i] == 0 ) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        primes = new int[100000]; Arrays.fill ( primes, 0 );
        primes[0] = 2; primes[1] = 3; primes[2] = 5; hwm = 3; nextCandidate = 5; delta = 2;
        Scanner in = new Scanner (System.in);
        int T = in.nextInt();
        while ( --T >= 0 ) {
            int n = in.nextInt();
            System.out.println( isPrime(n) ? "Prime" : "Not prime" );
        }
        in.close();
    }
}
