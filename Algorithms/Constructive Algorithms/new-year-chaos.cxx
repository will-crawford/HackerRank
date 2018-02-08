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
        while ( ++i != j )
            o << ' ' << *i;
    }
    return o;
}

int bribes ( vector<int> &Q, int N ) {
    int bribes = 0;
    // count back from the end. if we get to the front, we'd better have 1 in it, or we've gone wrong somewhere
    while ( --N > 0 ) {
        // we're expecting an integer equal to N
        if ( Q[N] == N )
            continue;
        int n, b;
        for ( n = N, b = 0; ++b, --n, Q[n] != N ; ) {
            if ( b == 2 || n == 0 )
                return -1;
        }
        bribes += b;
        auto i = begin(Q), left = i + n, middle = left + 1, right = i + N + 1;
        rotate ( left, middle, right );
    }
    return bribes;
}

int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int N; cin >> N;
        vector<int> Q (N); for ( int &q : Q ) cin >> q, --q;    // so they match the indices we're using!!
        int chaos = bribes ( Q, N );
        ( ( chaos < 0 ) ? ( cout << "Too chaotic" ) : ( cout << chaos ) ) << endl;
    }
    return 0;
}
