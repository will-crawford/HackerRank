#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int8_t> c (n); for ( auto & i : c ) { int tmp; cin >> tmp; i = int8_t(tmp); }
    int jumps = 0, last = n - 1;
    for ( int i = 0, next; i < last; ++jumps, i = next ) {
        if ( (next = i + 2) > last || c[next] )
            --next;
    }
    cout << jumps << endl;
    return 0;
}
