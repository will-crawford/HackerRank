#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline int reversed (int n) {
    int reverse = 0;
    while (n)
        reverse = reverse * 10 + n % 10, n /= 10;
    return reverse;
}

int main() {
    int i, j, k, count = 0; cin >> i >> j >> k;
    for ( int n = i; n <= j; ++n )
        if ( abs( n - reversed(n) ) % k == 0 )
            ++count;
    cout << count << endl;
    return 0;
}
