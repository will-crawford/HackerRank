#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        long B, W, X, Y, Z; cin >> B >> W >> X >> Y >> Z;
        long x = min( X, Y + Z ), y = min( Y, X + Z );
        cout << ( B * x + W * y ) << endl;
    }
    return 0;
}
