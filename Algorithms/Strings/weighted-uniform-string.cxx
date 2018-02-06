#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline void maximize ( int &i, int j ) { if ( i < j ) i = j; }

bool uniform_substring_exists ( int counts[], int x ) {
    for ( int i = 26, c; i > 0; --i )
        if ( ( c = counts[i] ) && ( x % i == 0 ) && x / i <= c )
            return true;
    return false;
}

int main() {
    string s; cin >> s;
    int n; cin >> n;
    int counts[27] = { 0, };
    {
        char last = 0;
        for ( int last = '\0', count, i = s.size(); --i >= 0; ) {
            if ( s[i] != last ) last = s[i], count = 1; else ++count;
            maximize ( counts[ s[i] - 'a' + 1 ], count );
        }
    }
    while ( --n >= 0 ) {
        int x; cin >> x;
        cout << ( uniform_substring_exists ( counts, x ) ? "Yes" : "No" ) << endl;
    }
    return 0;
}
