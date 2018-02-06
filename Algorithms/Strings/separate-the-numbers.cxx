#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int64_t beauty ( string &s, int l ) {
    int64_t first = 0, rollover = 1; auto p = begin(s), q = end(s);
    for ( int n = l; --n >= 0; rollover *= 10, first = first * 10 + *p++ - '0' )
        ;
    for ( int64_t nextExpected = first; ; ) {
        if ( ++nextExpected == rollover )
            rollover *= 10, ++l;
        if ( l > q - p )
            return 0;
        int64_t next = 0;
        for ( int n = l; --n >= 0; next = next * 10 + *p++ - '0' )
            ;
        if ( next != nextExpected )
            return 0;
        else if ( p == q )
            break;
    }
    return first;
}

int64_t beauty ( string &s ) {
    if ( s.length() < 2 || s[0] == '0' )
        return 0;
    int64_t result;
    for ( int l = 1, last = s.length() / 3; l <= last; ++l )
        if ( ( result = beauty ( s, l ) ) )
            return result;
    return beauty ( s, s.length() / 2 );
}

int main() {
    int q; cin >> q; while ( --q >= 0 ) {
        string s; cin >> s;
        int64_t b = beauty(s); ( b ? ( cout << "YES " << b ) : ( cout << "NO" ) ) << endl;
    }
    return 0;
}
