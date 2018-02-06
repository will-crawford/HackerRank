#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio (false);
    int n, k; cin >> n >> k;
    vector<int> a (n); for ( auto & i : a ) cin >> i;
    sort ( begin(a), end(a) );
    int count = 0;
    for ( int i = 0; i < a.size() - 1; ++i )
        for ( int j = i + 1; j < a.size(); ++j )
            if ( ( ( a[i] + a[j] ) % k ) == 0 )
                ++count;
    cout << count << endl;
    return 0;
}
