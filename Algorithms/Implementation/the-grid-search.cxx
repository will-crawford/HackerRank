#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

inline bool matchGrid ( const vector<string> &G, int startRow, int startCol, const vector<string> &P, int r, int c ) {
    for ( int i = 0; i < r; ++i )
        for ( int j = 0; j < c; ++j )
            if ( G[ startRow + i ][ startCol + j ] != P[i][j] )
                return false;
    return true;
}

inline bool match ( const vector<string> &G, int R, int C, const vector<string> &P, int r, int c ) {
    int maxRow = R - r, maxCol = C - c;
    for ( int startRow = 0; startRow <= maxRow; ++startRow ) {
        for ( int startCol = 0; startCol <= maxCol; ++startCol ) {
            if ( matchGrid ( G, startRow, startCol, P, r, c ) )
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio (false);
    streamsize ss = numeric_limits<streamsize>::max();
    int T; cin >> T;
    while ( --T >= 0 ) {
        int R, C; cin >> R >> C; cin.ignore (ss, '\n');
        vector<string> G (R); for ( auto &s : G ) { s.reserve(C); getline(cin, s); }
        int r, c; cin >> r >> c; cin.ignore (ss, '\n');
        vector<string> P (r); for ( auto &s : P ) { s.reserve(c); getline(cin, s); }
        cout << ( match ( G, R, C, P, r, c ) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
