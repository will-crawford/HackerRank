#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

bool wins ( vector<int> &s ) {
    int none = 0, one = 0, twoOrMore = 0;
    for ( int i : s ) if (i) if (i > 1) ++twoOrMore; else ++one; else ++none;
    if (twoOrMore > 1)
        return accumulate( begin(s), end(s), 0, bit_xor<>() );
    else if (twoOrMore)
        return true;
    else
        return !( one & 1 );
}

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int n; cin >> n; vector<int> s (n); while ( --n >= 0 ) cin >> s[n];
        cout << ( wins(s) ? "First" : "Second" ) << endl;
    }
    return 0;
}
