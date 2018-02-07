#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline void sort ( vector<int> &v ) { sort ( begin(v), end(v) ); }

int main() {
    ios_base::sync_with_stdio (false);
    int q, n, t;
    cin >> q; while ( --q >= 0 ) {
        cin >> n; vector<int> buckets (n, 0), balls (n, 0);
        for ( int & bucket : buckets ) for ( int & type : balls ) { cin >> t; bucket += t; type += t; }
        sort ( buckets ); sort ( balls ); cout << ( buckets == balls ? "Possible" : "Impossible" ) << endl;
    }
    return 0;
}
