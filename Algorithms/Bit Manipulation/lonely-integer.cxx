#include <cmath>
#include <cstdio>
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    array<int8_t,101> parity; parity.fill (0);
    while ( --n >= 0 ) { int ai; cin >> ai; parity[ai] ^= 1; }
    auto i = find ( begin(parity), end(parity), 1 );
    cout << ( i - begin(parity) ) << endl;
    return 0;
}
