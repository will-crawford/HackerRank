#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using IV = vector<int>;

enum { No, Yes, Swap, Reverse };
struct result { int sorted, l, r; };

template < typename T >
inline ostream & operator<< (ostream &os, vector<T> v) {
    os << '{';
    auto i = begin(v), j = end(v);
    if ( i != j ) {
        os << ' ' << *i;
        while ( ++i != j )
            os << ", " << *i;
    }
    return os << " }";
}

inline void warn ( const char * s ) { cerr << s << endl; }

result check_sorted ( IV &v ) {
    int end = v.size(); if ( end < 2 ) return { Yes };
    int l, r, last = end - 1;
    for ( l = 0; l < last && v[ l + 1 ] >= v[ l ]; ++l ) ;  // find ascending prefix
    if ( l == last ) return { Yes };
    for ( r = last; r > l && v[ r - 1 ] < v[ r ]; --r ) ;   // find ascending suffix
    // check whether swapping them would leave the array sorted ...
    // if the right hand one wouldn't fit on the left, or vice versa, give up :)
    if (
            ( l == 0 || v[r] >= v[l-1] )                 // else right one would still be too small on the left
         && ( r == last || v[l] <= v[r+1] )              // else left one would still be too big on the right
    ) {
        int i, current, next;
        for ( i = l + 1, current = v[i]; i < r && ( next = v[ ++i ] ) >= current; current = next )
            ;
        if ( i == r ) return { Swap, l, r };
        for ( i = l; v[ i + 1 ] <= v[ i ]; ++i )
            ;
        if ( i == r ) return { Reverse, l, r };
    }
    return { No };
}

int main() {
    int N; cin >> N;
    IV D (N); for ( auto &i : D ) cin >> i;
    result r = check_sorted (D);
    if ( r.sorted ) {
        cout << "yes";
        if ( r.sorted > Yes )
            cout << endl
                << ( r.sorted == Swap ? "swap" : "reverse" ) << ' ' << r.l + 1 << ' ' << r.r + 1;
    } else {
        cout << "no";
    }
    cout << endl;
    return 0;
}
