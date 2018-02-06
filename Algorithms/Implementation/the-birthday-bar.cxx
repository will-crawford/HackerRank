#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    int n, d, m; vector<int> s;
    cin >> n; s.resize(n); for ( auto &i : s ) cin >> i; cin >> d >> m;
    if ( m > n ) {
        cout << 0;
    } else {
        auto left = begin(s), right = left + m, last = end(s);
        int total = accumulate ( left, right, 0 ), count = 0;
        while (true) {
//            cerr << total << ( ( total == d ) ? " == " : " != " ) << d << endl;
            if ( total == d ) ++count;
            if ( right == last )
                break;
            total -= *left++;
            total += *right++;
        }
        cout << count;
    }
    cout << endl;
    return 0;
}
