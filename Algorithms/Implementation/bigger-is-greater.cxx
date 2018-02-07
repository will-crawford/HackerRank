#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool next_word ( string &w ) {
    if ( w.length() < 2 )
        return false;
    for ( auto i = end(w) - 1, j = i; i != begin(w); j = i )
        if ( *--i < *j ) {
            reverse ( j, end(w) );
            for ( ; j != end(w); ++j )
                if ( *j > *i ) {
                    swap ( *i, *j );
                    return true;
                }
        }
    return false;
}

int main() {
    int T; cin >> T;
    string dummy; getline ( cin, dummy );
    while ( --T >= 0 ) {
        string w; getline ( cin, w );
    //  quick answer:
    //  cout << ( next_permutation ( begin(w), end(w) ) ? w : "no answer" ) << endl;
        cout << ( next_word (w) ? w : "no answer" ) << endl;
    }
    return 0;
}
