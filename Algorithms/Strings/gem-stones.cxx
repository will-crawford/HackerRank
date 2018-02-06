#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bit_count (int32_t bits) { int n = 0; while (bits) ++n, bits &= (bits - 1); return n; }

int main() {
    int32_t gems = ~0L;
    int N; cin >> N; while ( --N >= 0 ) {
        string rock; cin >> rock;
        int32_t elements = 0; for ( auto c : rock ) elements |= 1 << ( c - 'a' );
        gems &= elements;
    }
    cout << bit_count(gems) << endl;
    return 0;
}
