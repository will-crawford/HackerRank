#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

int main() {
    int n; cin >> n; vector<int> A (n); for ( int &i : A ) cin >> i;
    int m; cin >> m; vector<int> B (m); for ( int &i : B ) cin >> i;
    int base = *min_element(begin(B), end(B));
    vector<int> a (101, 0), b (101, 0); for ( auto i : A ) ++a[ i - base ]; for ( auto i : B ) ++b[ i - base ];
    for ( int i = 0; i < 101; ++i )
        if ( a[i] != b[i] )
            cout << base + i << ' ';
    cout << endl;
    return 0;
}
