#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// DP version, after reading some of the discussion ...

ostream &operator<< ( ostream &os, vector<int> &v ) {
    auto i = begin(v), j = end(v);
    if ( i != j ) {
        os << *i;
        while ( ++i != j )
            os << ' ' << *i;
    }
    return os;
}
void populate_powers ( vector<int> &powers, int X, int N ) {
    powers.push_back (1);
    for ( int n = 2; ; ++n ) {
        int p = 1;
        for ( int i = N; --i >= 0; )
            if ( ( p *= n ) > X )
                return;
        powers.push_back (p);
    }
}

int main() {
    int X, N; cin >> X >> N;
    vector<int> powers; populate_powers (powers, X, N); cerr << "powers = " << powers << endl;
    vector<int> ways (X + 1, 0);
    ways[0] = 1;
    for ( auto &p : powers )
        for ( int i = X - p; i >= 0; --i )
            ways[ i + p ] += ways[ i ];
    cerr << "ways = " << ways << endl;
    cout << ways[X] << endl;
    return 0;
}
