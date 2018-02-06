#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check ( const string &haystack, const char *needles ) {
    for ( auto p = begin(haystack), q = end(haystack); *needles; ++p, ++needles ) {
        if ( p == q ) return false;
        if ( ( p = find ( p, q, *needles ) ) == q ) return false;
    }
    return true;
}

int main() {
    int q; cin >> q; string s; s.reserve(10001); getline(cin, s);   // skip the end of line
    while ( --q >= 0 ) {
        getline(cin, s);
        cout << ( check ( s, "hackerrank" ) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
