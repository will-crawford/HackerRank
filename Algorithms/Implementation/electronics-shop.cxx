#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ostream & operator<< ( ostream &os, vector<int> &v ) {
    auto i = begin(v), last = end(v);
    if ( i != last ) {
        cerr << *i;
        while ( ++i != last )
            cerr << ' ' << *i;
    }
    return os;
}

inline void sort ( vector<int> &v ) { sort ( begin(v), end(v), greater<>() ); }

int hunt ( vector<int> &N, vector<int> &M, int s ) {
    int spend = -1;
    for ( auto &n : N ) {
        if ( n + M[0] < spend )
            break;
        for ( auto &m : M ) {
            if ( n + m < spend )
                break;
            else if ( n + m <= s ) {
                spend = n + m;
                if ( n + m == s )
                    return spend;
            }
        }
    }
    return spend;
}

int main() {
    int s, n, m; cin >> s >> n >> m; cerr << s << ' ' << n << ' ' << m << endl;
    vector<int> N (n); for ( auto &i : N ) cin >> i; sort( N ); cerr << N << endl;
    vector<int> M (m); for ( auto &i : M ) cin >> i; sort( M ); cerr << M << endl;
    cout << hunt( N, M, s ) << endl;
    return 0;
}
