import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Pattern pattern = Pattern.compile( ".*@gmail\\.com" );
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        ArrayList<String> nameList = new ArrayList<String>();
        for(int a0 = 0; a0 < N; a0++){
            String firstName = in.next();
            String emailID = in.next();
            Matcher matcher = pattern.matcher(emailID);
            if ( matcher.matches() ) { nameList.add( firstName ); }
        }
        String[] nameArray = nameList.toArray( new String[ nameList.size() ] );
        Arrays.sort( nameArray );
        for ( String s : nameArray ) { System.out.println(s); }
    }
}
