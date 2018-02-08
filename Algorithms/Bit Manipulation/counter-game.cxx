#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

uint64_t high_bit ( uint64_t N ) {
    for ( uint64_t O; ( O = N & ( N - 1 ) ); N = O )
        ;
    return N;
}

bool wins ( uint64_t N ) {
    if ( N == 1 )
        return false;
    uint64_t bit = high_bit (N);
    return !wins( bit == N ? ( bit >> 1 ) : ( N &~ bit ) );
}

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        uint64_t N; cin >> N; cout << ( wins(N) ? "Louise" : "Richard" ) << endl;
    }
    return 0;
}
