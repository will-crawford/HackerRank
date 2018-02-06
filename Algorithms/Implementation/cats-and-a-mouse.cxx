#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q; cin >> q;
    while ( --q >= 0 ) {
        int x, y, z; cin >> x >> y >> z;
        int dx = abs( z - x ), dy = abs( z - y );
        cout << ( dx < dy ? "Cat A" : dx > dy ? "Cat B" : "Mouse C" ) << endl;
    }
    return 0;
}
