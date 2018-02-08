#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int64_t q; cin >> q; while ( --q >= 0 ) {
        int64_t x; cin >> x;
        int64_t na = 0;
        for ( int64_t bit = 1; bit < x; bit <<= 1 )
            if ( !( x & bit ) )
                na += bit;
        cout << na << endl;
    }
    return 0;
}
