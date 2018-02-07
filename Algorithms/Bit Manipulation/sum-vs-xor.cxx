#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int64_t n, result = 1; cin >> n;
    while ( n ) { if ( !( n & 1 ) ) result <<= 1; n >>= 1; }
    cout << result << endl;
    return 0;
}
