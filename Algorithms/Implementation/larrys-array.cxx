#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define D(e) cerr << #e " = " << (e) << endl
inline ostream &operator<< ( ostream &o, vector<int>::iterator &p ) { return o << static_cast<void*>(&*p); }

void debug ( vector<int> &A, int N ) {
    auto i = begin(A); cerr << *i;
    while ( --N > 0 ) cerr << ' ' << *++i;
    cerr << endl;
}

bool can_sort ( vector<int> &A, int N ) {
    auto a = begin(A), end = a + N;
    if ( N < 3 )
        return end == is_sorted_until( a, end );
    for ( auto stop = a + 2; end > stop; --end ) {
        auto left = max_element ( a, end );
        auto d = end - left;
        if ( d >= 3 ) {
            auto bloc = ( d & 1 ) ? d : d - 1;
            rotate( left, left + 1, left + bloc );
            d = d - bloc + 1;
        }
        switch (d) {
//          case 3: rotate( end - 3, end - 1, end ); break;
          case 2: rotate( end - 3, end - 1, end ); break;
          default: /* nothing to do */ ;
        }
    }
    return N >= 3 && A[1] >= A[0] && A[2] >= A[1];
}

int main() {
    int T, N; vector<int> A;
    cin >> T;
    while ( --T >= 0 ) {
        cin >> N;
        if ( N > A.size() ) A.resize(N);
        for ( int i = N, *p = A.data(); --i >= 0; cin >> *p++ )
            ;
        cout << ( can_sort(A, N) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
