#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct magic_t {
    int s[9];
    void FlipLR () { swap( s[0], s[2] ); swap( s[3], s[5] ); swap( s[6], s[8] ); }
    void FlipTB () { swap( s[0], s[6] ); swap( s[1], s[7] ); swap( s[2], s[8] ); }
    void Rotate () {
        int tmp = s[0]; s[0] = s[2]; s[2] = s[8]; s[8] = s[6]; s[6] = tmp;
            tmp = s[1]; s[1] = s[5]; s[5] = s[7]; s[7] = s[3]; s[3] = tmp;
    }
    int difference (const magic_t &rhs) const {
        int d = 0, i = 0;
        while (true) { d += abs( s[i] - rhs.s[i] ); if ( i == 8 ) break; ++i; }
        return d;
    }
};

const magic_t magic = { { 2, 7, 6, 9, 5, 1, 4, 3, 8 } };

void ClampDown ( int &minimum, int d ) { if ( d < minimum ) minimum = d; }

int main() {
    magic_t input; for ( auto &i : input.s ) cin >> i;
    int minimum = magic.difference (input);
    input.FlipLR(); ClampDown( minimum, input.difference (magic) );
    input.FlipTB(); ClampDown( minimum, input.difference (magic) );
    input.FlipLR(); ClampDown( minimum, input.difference (magic) );
    input.Rotate(); ClampDown( minimum, input.difference (magic) );
    input.FlipLR(); ClampDown( minimum, input.difference (magic) );
    input.FlipTB(); ClampDown( minimum, input.difference (magic) );
    input.FlipLR(); ClampDown( minimum, input.difference (magic) );
    cout << minimum << endl;
    return 0;
}
