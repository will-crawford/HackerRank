#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

uint64_t Tn ( uint64_t N ) {
//    static const uint64_t bits[4] = { 0, 1, 1, 0 };
//    return ( ( N & 1 ) ? 0 : N ) | bits[ N & 3 ];
    switch ( N & 3ULL ) {
        case 0: return N;
        case 1: return 1ULL;
        case 2: return N|1ULL;
        case 3: return 0ULL;
        default: throw("compiler is broken");
    }
    //return 0ULL;
}

uint64_t Xn ( uint64_t N ) {
    switch ( N & 7ULL ) {
        case 0: case 1: return N;
        case 2: case 3: return 2ULL;
        case 4: case 5: return N|2ULL;
        case 6: case 7: return 0ULL;
        default: // this is annoying, because in theory this is unreachable(!)
            throw "compiler is stupid";
    }
}

uint64_t xor_sum ( uint64_t L, uint64_t R ) { return Xn(R) ^ Xn(L-1); }

int main() {
    int Q; cin >> Q;
    while ( --Q >= 0 ) {
        uint64_t L, R; cin >> L >> R;
        cout << xor_sum ( L, R ) << endl;
    }
    return 0;
}
