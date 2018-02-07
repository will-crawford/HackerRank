#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define D(e) cerr << #e " = " << (e) << endl

int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int N, K; cin >> N >> K;
        if ( K && ( K > N / 2 || N % ( 2 * K ) ) ) {
            cout << -1;
        } else if ( !K ) {
            cout << 1;
            for ( int n = 2; n <= N; ++n )
                cout << ' ' << n;
        } else {
            int delta = K;
            cout << ( 1 + delta );
            for ( int n = 2, counter = K - 1; n <= N; ++n, --counter ) {
                if ( counter <= 0 )
                    counter = K, delta = -delta;
                cout << ' ' << ( n + delta );
            }
        }
        cout << endl;
    }
    return 0;
}
