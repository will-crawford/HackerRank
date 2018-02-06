#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<int> t (n); for ( int &i : t ) cin >> i;
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
    cout << special << endl;
    return 0;
}
