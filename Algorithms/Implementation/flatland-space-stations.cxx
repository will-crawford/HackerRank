#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    if ( n == m ) {
        cout << 0 << endl;
    } else {
        vector<int> s(m); for ( auto &i : s ) cin >> i;
        sort ( begin(s), end(s) );
        int md = max( s.front(), n - 1 - s.back() );
        for ( int i = 0; i < m - 1; ++i ) {
            int d = ( s[i+1] - s[i] ) / 2;
            if ( d > md ) md = d;
        }
        cout << md << endl;
    }
    return 0;
}
