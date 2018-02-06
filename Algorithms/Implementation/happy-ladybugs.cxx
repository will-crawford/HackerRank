#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool happy ( const string &b ) {
    auto l = b.size();
    for ( int i = 0, j; i < l; i = j ) {
        char colour = b[i];
        for ( j = i; ++j < l && b[j] == colour; )
            ;
        if ( colour != '_' && ( j - i ) == 1 )
            return false;
    }
    return true;
}

inline bool unhappy ( int (&counts)[26] ) {
    for ( int i : counts )
        if ( i == 1 )
            return true;
    return false;
}

inline bool can ( const string &b ) {
    int gaps = 0, counts[26] = { 0, };
    for ( char c : b ) ( c == '_' ) ? ++gaps : ++counts[ c - 'A' ];
    return gaps ? !unhappy ( counts ) : happy ( b );
}

int main() {
    int g; cin >> g;
    while ( --g >= 0 ) {
        int n; cin >> n; string b; cin >> b;
        cout << ( can(b) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
