#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, T; cin >> N >> T;
    vector<int> width (N); for ( auto &i : width ) cin >> i;
    while ( --T >= 0 ) {
        int i, j, mw = 3; cin >> i >> j;
        do {
            int w = width[i];
            if ( w < mw )
                mw = w;
        } while ( ++i <= j );
        cout << mw << endl;
    }
    return 0;
}
