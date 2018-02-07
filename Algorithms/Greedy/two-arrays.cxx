#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool totals_ok ( vector<int> &a, vector<int> &b, int k ) {
    for ( int i = a.size(); --i >= 0; )
        if ( ( a[i] + b[i] ) < k )
            return false;
    return true;
}

int main() {
    int q; cin >> q; while ( --q >= 0 ) {
        int n, k; cin >> n >> k;
        vector<int> A (n), B (n); for ( int &i : A ) cin >> i; for ( int &i : B ) cin >> i;
        sort( begin(A), end(A), greater<>() ); sort( begin(B), end(B) );
        cout << ( totals_ok( A, B, k ) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
