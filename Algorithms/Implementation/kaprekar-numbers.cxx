#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const uint64_t powers[] = {
    1UL, 10UL, 100UL, 1000UL, 10000UL, 100000UL, 1000000UL, 10000000UL, 100000000UL, 1000000000UL,
};

inline int digits (uint64_t n) {
    int d = 0;
    while (n)
        ++d, n /= 10;
    return d;
}

int main() {
    int p, q; cin >> p >> q;
    int count = 0;
    for ( uint64_t n = p, square = n * n; n <= q; square += 2 * n++ + 1 ) {
        int d = digits (square), r = ( d  + 1 ) / 2, l = d - r;
        if ( n == square / powers[r] + square % powers[r] )
            ++count, cout << n << ' ';
    }
    if (!count)
        cout << "INVALID RANGE";
    cout << endl;
    return 0;
}
