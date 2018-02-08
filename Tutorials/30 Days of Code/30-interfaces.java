import java.io.*;
import java.util.*;

interface AdvancedArithmetic{
   int divisorSum(int n);
}
class Calculator implements AdvancedArithmetic {
    public int divisorSum (int n) {
        int total = 0;
        int limit = (int) Math.floor( Math.sqrt(n) );
        for ( int i = 1; i <= limit; ++i ) {
            if ( n % i == 0 ) {
                int dividend = n / i;
                total += i;
                if ( i != dividend )
                    total += dividend;
            }
        }
        return total;
    }
}
class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();
        
      	AdvancedArithmetic myCalculator = new Calculator(); 
        int sum = myCalculator.divisorSum(n);
        System.out.println("I implemented: " + myCalculator.getClass().getInterfaces()[0].getName() );
        System.out.println(sum);
    }
}
