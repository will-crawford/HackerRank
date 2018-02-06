#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int N, K; cin >> N >> K;
        while ( --N >= 0 ) {
            int a; cin >> a;
            if ( a <= 0 )
                --K;
        }
        cout << ( K <= 0 ? "NO" : "YES" ) << endl;
    }
    return 0;
}
