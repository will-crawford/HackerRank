#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define D(e) cerr << #e " = " << (e) << endl

inline ostream &operator<< ( ostream &o, vector<int> &v ) {
    auto i = begin(v), j = end(v);
    if ( i != j ) {
        o << *i;
        while ( ++i != j ) o << ' ' << *i;
    }
    return o;
}

template <typename T>
inline ostream &operator<< (ostream &o, vector< vector<T> > &v) { for ( vector<T> &row : v ) o << row << endl; return o; }

inline void debug_matrix ( ostream &o, vector<int> &m, int M, int N ) {
    for ( auto mp = m.data(); --M >= 0; ++mp ) {
        o << *mp;
        for ( int i = N; --i > 0; o << ' ' << *++mp )
            ;
        o << endl;
    }
    o << endl;
}
inline void debug_vector ( ostream &o, vector<int> &v, int r, int c, bool pivot ) {
    int *p = v.data(), i = 0, j = 2 * r + 2 * c - 4;
    o << p[i]; while ( ++i < c ) o << ' ' << p[i]; o << endl;
    for ( --r; --r > 0; ) {
        o << p[--j]; for ( int n = c - 1; --n > 0; o << " _" ) ; o << ' ' << p[i++] << endl;
    }
    o << p[--j]; while ( i < j ) o << ' ' << p[--j]; o << endl;
}

template <typename Action>
void copy ( int *&vp, int *&mp, int s, int n, Action a ) { for ( ; --n; mp += s ) a ( *vp++, *mp ); }
template <typename Action>
inline void copy ( vector<int> &v, vector<int> &m, int y, int x, int r, int c, int rs, int cs, Action a ) {
    int *vp = v.data(), *mp = m.data() + y * rs + x * cs;
    copy ( vp, mp, cs, c, a );
    copy ( vp, mp, rs, r, a );
    copy ( vp, mp, -cs, c, a );
    copy ( vp, mp, -rs, r, a );
}
inline void copy_out ( vector<int> &from, vector<int> &to, int y, int x, int r, int c, int rs, int cs ) {
    copy ( to, from, y, x, r, c, rs, cs, [] ( int &v, int &m ) { v = m; } );
}
inline void copy_in ( vector<int> &from, vector<int> &to, int y, int x, int r, int c, int rs, int cs ) {
    copy ( from, to, y, x, r, c, rs, cs, [] ( int &v, int &m ) { m = v; } );
}

void rotate ( vector<int> &m, int M, int N, int R ) {
    bool pivot = M > N;
    int r, c, rs, cs; if ( pivot ) r = N, c = M, rs = 1, cs = N; else r = M, c = N, rs = N, cs = 1;
    for ( int x = 0, y = 0, size = 2 * r + 2 * c - 4; r; ++x, ++y, r -= 2, c -= 2, size -= 8 ) {
        int n = R % size;
        if ( n ) {
            vector<int> v (size, 0);
            copy_out ( m, v, y, x, r, c, rs, cs );
            rotate ( begin(v), begin(v) + ( pivot ? ( size - n ) : n ), end(v) );
            copy_in ( v, m, y, x, r, c, rs, cs );
        }
    }
}

int main() {
    int M, N, R; cin >> M >> N >> R;
    vector<int> m ( M * N ); for ( int &i : m ) cin >> i;
    rotate ( m, M, N, R );
    debug_matrix ( cout, m, M, N );
    return 0;
}
