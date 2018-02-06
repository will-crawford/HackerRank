#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k, h, hMax = 0; cin >> n >> k;
    while ( --n >= 0 ) { cin >> h; if ( h > hMax ) hMax = h; }
    cout << max( 0, hMax - k ) << endl;
    return 0;
}
