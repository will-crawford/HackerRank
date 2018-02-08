import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int fine ( int Da, int Ma, int Ya, int De, int Me, int Ye ) {
        if ( Ya > Ye ) return 10000;
        if ( Ya == Ye ) {
            if ( Ma > Me ) return 500 * ( Ma - Me );
            if ( Ma == Me ) {
                if ( Da > De ) return 15 * ( Da - De );
            }
        }
        return 0;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        int Da = in.nextInt(), Ma = in.nextInt(), Ya = in.nextInt(),
            De = in.nextInt(), Me = in.nextInt(), Ye = in.nextInt();
        in.close();
        System.out.println ( fine( Da, Ma, Ya, De, Me, Ye ) );
    }
}
