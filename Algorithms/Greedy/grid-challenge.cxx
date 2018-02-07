#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_column_sorted ( vector<string> &G, int column ) {
    for ( int row = G.size(), current = G[--row][column], next; --row >= 0; current = next )
        if ( ( next = G[row][column] ) > current )
            return false;
    return true;
}

bool is_column_sorted ( vector<string> &G ) {
    for ( int column = G.size(); --column >= 0; )
        if ( ! is_column_sorted ( G, column ) )
            return false;
    return true;
}

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int N; cin >> N;
        vector<string> G (N); for ( auto &s : G ) { cin >> s; sort(begin(s), end(s)); }
        cout << ( is_column_sorted (G) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
