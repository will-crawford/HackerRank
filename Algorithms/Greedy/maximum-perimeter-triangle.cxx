#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    vector<uint32_t> L (N); for ( uint32_t &i : L ) cin >> i;
    sort( begin(L), end(L), greater<>() );
    uint32_t perimeter = 0; struct { uint32_t li, lj, lk; } sides = { 0, 0, 0 };
    for ( int i = 0, iLast = 0; i < N - 2; ++i ) {
        uint32_t li = L[i]; if ( li == iLast ) continue; iLast = li;
        uint32_t jMin = li / 2 + 1;   // must be *more* than half li
        for ( int j = i, jLast = 0; ++j < N - 1; ) {
            uint32_t lj = L[j]; if ( lj == jLast ) continue; jLast = lj;
            if ( lj < jMin ) break;  // next in the list is no bigger, so lj must be more than half of li
            uint32_t ijSum = li + lj, ijDiff = li - lj;
            for ( int k = j, kLast = 0; ++k < N; ) {
                uint32_t lk = L[k]; if ( lk == kLast ) continue; kLast = lk;
                if ( lk <= ijDiff ) break;  // if equal, triangle is degenerate; if less, it's impossible
                uint32_t ijkSum = ijSum + lk;
                if (
                    ijkSum > perimeter
                 || ijkSum == perimeter && ( li > sides.li || li == sides.li && lk > sides.lk )
                )
                    perimeter = ijkSum, sides = { li, lj, lk };
            }
        }
    }
    if ( !perimeter )
        cout << -1;
    else
        cout << sides.lk << ' ' << sides.lj << ' ' << sides.li;
    cout << endl;
    return 0;
}
