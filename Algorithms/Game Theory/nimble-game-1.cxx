#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int n, ci, xs = 0;
        cin >> n;
        //cerr << dec << n << endl;
        for ( int i = 0; i < n; ++i ) {
            cin >> ci;
            //cerr << "ci = " << dec << ci << endl;
            if ( ci & 1 ) {
                xs ^= i;
                //cerr << hex << "i = " << i << ", xs = " << xs << endl;
            }
        }
        cout << ( xs ? "First" : "Second" ) << endl;
    }
    return 0;
}
