#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    bool wins[101] = { false, false, true, true, true, true, };
    for ( int n = 5; n <= 100; ++n )
        wins[n] = !( wins[n-5] && wins[n-3] && wins[n-2] );
    int T; cin >> T; while ( --T >= 0 ) {
        int n; cin >> n; cout << ( wins[n] ? "First" : "Second" ) << endl;
    }
    return 0;
}
