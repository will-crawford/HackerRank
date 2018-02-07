#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline uint32_t high_bit ( uint32_t n ) {
    for ( int next; next = n & ( n - 1 ); n = next )
        ;
    return n;
}

int main() {
    int l, r; cin >> l >> r;
    uint32_t L(l), R(r), A = L, B = R;
    for ( int bit = high_bit(L|R), shared = ~(L^R); bit; bit >>= 1 ) {
        if ( shared & bit ) {
            uint32_t Ab = A^bit, Bb = B^bit;
            if ( Bb > A && Bb <= R )
                B = Bb;
            else if ( Ab < B && Ab >= L )
                A = Ab;
        }
    }
    cout << (A^B) << endl;
    return 0;
}
