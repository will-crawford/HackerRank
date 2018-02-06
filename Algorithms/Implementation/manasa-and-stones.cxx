#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int n, a, b; cin >> n >> a >> b; if ( a > b ) swap ( a, b );
        int first = a * --n; cout << first;
        int step = b - a;
        if ( step )
            do cout << ' ' << ( first += step ); while (--n);
        cout << endl;
    }
    return 0;
}
