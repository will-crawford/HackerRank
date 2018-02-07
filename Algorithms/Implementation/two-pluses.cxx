#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = numeric_limits<int>::max();

template <typename T>
inline ostream &operator<< ( ostream &o, vector<T> &v ) {
    auto i = begin(v), j = end(v);
    if ( i != j ) { o << *i; while ( ++i != j ) o << ' ' << *i; } return o;
}
ostream &operator<< ( ostream &o, vector<string> &v ) { for ( auto &s : v ) o << s << endl; return o << endl; }
template <typename T>
inline ostream &operator<< ( ostream &o, vector< vector<T> >&v ) { for ( auto &row: v ) o << row << endl; return o; }

inline void convert ( vector<string> &NM, vector<int> &R ) {
    auto p = R.data(); for ( auto &row : NM ) for ( auto c : row ) *p++ = ( c == 'G' ) ? MAX : 0;
}

inline void clampDown ( int &minimum, int i ) { if ( i < minimum ) minimum = i; }
inline void clampUp ( int &maximum, int i ) { if ( i > maximum ) maximum = i; }
inline void biggestFirst ( int &a, int &b ) { if ( a < b ) swap ( a, b ); }

inline void step ( int &i, int &r ) { if ( i ) clampDown ( i, ++r ); else r = 0; }
inline void step ( int *i, int &r ) { step ( *i, r ); }
inline void runs ( int *p, int m, int cs ) {
    int rl = 0; for ( int j = m; --j >= 0; p += cs ) step ( p, rl );
    rl = 0; do step ( p -= cs, rl ); while ( --m );
}
inline void runs ( int *p, int n, int m, int rs, int cs ) { for ( int i = n; --i >= 0; p += rs ) runs ( p, m, cs ); }
inline void runs_both_ways ( int *p, int N, int M ) { runs ( p, N, M, M, 1 ); runs ( p, M, N, 1, M ); }

void convert ( vector<int> &R, vector< vector<int> > &G ) {
    auto p = begin(R); for ( vector<int> &row : G ) for ( int &column : row ) column = *p++;
}

inline int square ( int n ) { return n * n; }
inline int area ( int n ) { return 4 * n - 3; }
inline int areaProduct ( int n ) { return square( area ( n ) ); }
inline int areaProduct ( int first, int second ) { return area ( first ) * area ( second ); }

inline void updateMaximum ( int &m, int plusOne, int plusTwo ) { clampUp ( m, areaProduct ( plusOne, plusTwo ) ); }

bool intersects ( int dx, int dy, int plusOne, int plusTwo ) {
    biggestFirst ( dx, dy ); biggestFirst ( plusOne, plusTwo );
    return ( dx == 0 ) || (
        dy ? ( dy < plusTwo ? dx < plusOne : ( dy < plusOne && dx < plusTwo ) ) : ( dx < ( plusOne + plusTwo - 1 ) )
    );
}
bool fits ( int dx, int dy, int plusOne, int plusTwo ) { return ! intersects ( dx, dy, plusOne, plusTwo ); }

// recurse to find smaller ones that fit if necessary
int find_maximal_pair ( int dx, int dy, int plusOne, int plusTwo, int &maximum ) {
    if ( !( plusOne && plusTwo ) )
        return 0;
    return
        fits ( dx, dy, plusOne, plusTwo ) ? areaProduct ( plusOne, plusTwo ) : max (
            find_maximal_pair ( dx, dy, plusOne - 1, plusTwo, maximum ),
            find_maximal_pair ( dx, dy, plusOne, plusTwo - 1, maximum )
        )
    ;
}

int find_maximal_pair ( vector< vector<int> > &G, int N, int M ) {
    int maximum = 0;
    for ( int n = 0; n < N; ++n ) {
        for ( int m = 0; m < M; ++m ) {
            int plusOne = G[n][m];
            if ( !plusOne )
                continue;
            // now look strictly below or to the right for a second pair
            for ( int j = m + 1; j < M; ++j ) {
                int plusTwo = G[n][j];
                if ( !plusTwo )
                    continue;
                int x = find_maximal_pair ( 0, j - m, plusOne, plusTwo, maximum );
                clampUp ( maximum, x );
            }
            for ( int i = n + 1, dy = 1; i < N; ++i, ++dy ) {
                for ( int j = 0; j < M; ++j ) {
                    int dx = abs( j - m );
                    int plusTwo = G[i][j];
                    if ( !plusTwo )
                        continue;
                    int x = find_maximal_pair ( dx, dy, plusOne, plusTwo, maximum );
                    clampUp ( maximum, x );
                }
            }
        }
    }
    return maximum;
}
int main() {
    int N, M; cin >> N >> M;
    vector<string> NM (N); for ( string &row : NM ) cin >> row;
    vector<int> R ( N * M ); convert ( NM, R );
    runs_both_ways ( R.data(), N, M );
    vector< vector<int> > G ( N, vector<int> (M) ); convert ( R, G );
    int product = find_maximal_pair ( G, N, M );
    cout << product << endl;
    return 0;
}
