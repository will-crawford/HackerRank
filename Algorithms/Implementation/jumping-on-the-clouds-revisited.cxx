#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<int8_t> c (n); for ( auto & cloud : c ) { int i; cin >> i; cloud = int8_t(i); }
    int E = 100, i = 0;
    do
        i = ( i + k ) % n, E -= ( 1 + 2 * int( c[i] ) );
    while (i);
    cout << E << endl;
    return 0;
}
