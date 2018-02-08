#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q; cin >> q;
    while ( --q >= 0 ) {
        int n; cin >> n;
        int N = 2 * n, last = N - 1, total = 0;
        vector< vector<int> > M ( N, vector<int> (N) );
        for ( vector<int> &row : M )
            for ( int &i : row )
                cin >> i;
        for ( int t = 0, b = N - 1; t < n; ++t, --b )
            for ( int l = 0, r = N - 1; l < n; ++l, --r )
                total += max ( max ( M[t][l], M[t][r] ), max ( M[b][l], M[b][r] ) );
        cout << total << endl;
    }
    return 0;
}
