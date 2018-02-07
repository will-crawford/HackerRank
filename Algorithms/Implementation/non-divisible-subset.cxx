#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<int> counts (k, 0);
    for ( int i = n, Si; --i >= 0; cin >> Si, ++counts[ Si % k ] )
        ;
    int i, j;
    for ( i = 0, j = counts.size(); ++i < --j; n -= min( counts[i], counts[j] ) )
        ;
    if ( i == j && counts[i] )
        n -= ( counts[i] - 1 );
    if ( counts[0] )
        n -= ( counts[0] - 1 );
    cout << n << endl;
    return 0;
}
