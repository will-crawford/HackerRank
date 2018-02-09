import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner (System.in);
        int n = in.nextInt(), k = in.nextInt();
        int[] t = new int[n]; for ( int i = 0; i < n; ++i ) { t[i] = in.nextInt(); }

        int special = 0;
        // the chapter might be numbered '1', but we need to index the vector
        for ( int chapter = 0, page = 1, nextChapterPage; chapter < n; ++chapter, page = nextChapterPage ) {
            int problemsInChapter = t[chapter], pagesInChapter = ( problemsInChapter + k - 1 ) / k;
            nextChapterPage = page + pagesInChapter;
            if ( page > problemsInChapter )
                continue;
            for ( int problem = 1, nextPageProblem; page < nextChapterPage; ++page, problem = nextPageProblem ) {
                nextPageProblem = problem + k;
                if ( page >= problem && page < nextPageProblem && page <= problemsInChapter )
                    ++special;
            }
        }
        System.out.println (special);
    }
}
