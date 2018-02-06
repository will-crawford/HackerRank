#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void hits ( uint32_t st, uint32_t offset, int count ) {
    int n = 0;
    int32_t x;
    while ( --count >= 0 ) {
        cin >> x;
        if ( uint32_t( uint32_t( x ) + offset ) <= st )
            ++n;
    }
    cout << n << endl;
}

int main() {
    int32_t s, t, a, b, m, n;
    cin >> s >> t >> a >> b >> m >> n;
    hits ( uint32_t( t - s ), ( a - s ), m );
    hits ( uint32_t( t - s ), ( b - s ), n );
    return 0;
}
