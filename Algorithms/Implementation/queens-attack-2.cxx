#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
using namespace std;

ostream & operator<< ( ostream &os, int (v)[8] ) {
    auto i = v, e = v + 8;
    os << *i; while ( ++i != e ) os << ' ' << *i;
    return os;
}

enum { N, NE, E, SE, S, SW, W, NW };
void ClampDown ( int &s, int i ) { if ( i < s ) s = i; }

int main() {
    int n, k, rq, cq; cin >> n >> k >> rq >> cq;
    // squares to N, NE, E ..., NW (including the queen's square - subtract later)
    int squares[8] = {
        rq,         min( rq, n + 1 - cq ), n + 1 - cq,  min( n + 1 - cq, n + 1 - rq ),
        n + 1 - rq, min( n + 1 - rq, cq ), cq,          min ( rq, cq )
    };
    cerr << squares << endl;
    while ( --k >= 0 ) {
        int ri, ci; cin >> ri >> ci;
        int dy = abs( ri - rq ), dx = abs( ci - cq );
        if ( !dy )
            ClampDown( squares[ ci < cq ? W : E ], dx ); // same row, which side?
        else if ( !dx )
            ClampDown( squares[ ri < rq ? N : S ], dy ); // same column ...
        else if ( dy == dx )
            ClampDown( squares[ ci < cq ? ( ri < rq ? NW : SW ) : ( ri < rq ? NE : SE ) ], dx );
    }
    cerr << squares << endl;
    int total = accumulate( squares, squares + 8, 0 );
    cout << total - 8 << endl;
    return 0;
}
