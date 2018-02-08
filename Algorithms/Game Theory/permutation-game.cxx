#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const uint16_t bits[] = {
         1,      2,      4,      8,
      0x10,   0x20,   0x40,   0x80,
     0x100,  0x200,  0x400,  0x800,
    0x1000, 0x2000, 0x4000, 0x8000,
    0
};
const size_t masks[] = {
         1,      2,      4,      8,   0x10,   0x20,   0x40,   0x80,
     0x100,  0x200,  0x400,  0x800, 0x1000, 0x2000, 0x4000, 0x8000,
};
//enum { Unknown, Loses, Wins };

bool IsSorted ( vector<int> &n, uint16_t mask ) {
//    if ( !( mask & ( mask - 1 ) ) )
//        return true;
    for ( int previous = 0, current, bit = 0, bitMask; bitMask = bits[bit]; ++bit ) {
        if ( ( mask & bitMask ) ) {
            if ( ( current = n[bit] ) <= previous )
                return false;
            else
                previous = current;
        }
    }
    return true;
}

inline bool SetKnown ( int8_t &known, bool value ) { known = int8_t( value ) + 1; return value; }

bool CanWin ( vector<int> &n, vector<int8_t> &memo, uint16_t mask ) {
    int8_t &known = memo[mask];
    if ( known )
        return bool( known - 1 );

    if ( IsSorted ( n, mask ) )
        return SetKnown ( known, false );

    // assume mask is non-zero at this point(!)
    for ( int bit = 0, bitMask; bitMask = bits[bit]; ++bit ) {
        if ( mask & bitMask ) {
            uint16_t testMask = mask &~ bitMask;
            if ( ! CanWin ( n, memo, testMask ) ) return SetKnown ( known, true );
        }
    }
    return SetKnown ( known, false );
}

bool CanWin ( vector<int> &n ) {
    size_t M = masks[ n.size() ], ALL = uint16_t( M - 1 );
    vector<int8_t> memo (M, 0); return CanWin ( n, memo, ALL );
}

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int N; cin >> N; vector<int> n (N); for ( auto &i : n ) cin >> i;
        cout << ( CanWin(n) ? "Alice" : "Bob" ) << endl;
    }
    return 0;
}
