#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k, q; cin >> n >> k >> q; int offset = n - ( k % n );
    vector<int> a(n);
    for ( int i = 0; i < n; ++i )
        cin >> a[i];
    while (q) {
        int m; cin >> m;
        cout << a[ ( m + offset ) % n ] << endl;
        --q;
    }
    return 0;
}
