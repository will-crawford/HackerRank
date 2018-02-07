#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int n, k; cin >> n >> k;
        int x = 0; while ( --n >= 0 ) { int ci; cin >> ci; x ^= ci; }
        cout << ( x ? "First" : "Second" ) << endl;
    }
    return 0;
}
