#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL = int64_t;

int main() {
    int n; cin >> n;
    vector<int> c (n); for ( auto i = n; --i >= 0; ) cin >> c[i];
    sort ( begin(c), end(c), greater<>() );
    int64_t miles = 0, pot = 1;
    for ( int i = 0; i < n; ++i, pot <<= 1 )
        miles += pot * c[i];
    cout << miles << endl;
    return 0;
}
