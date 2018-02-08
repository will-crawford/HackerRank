#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int N, K, maxAB = 0; cin >> N >> K;
        for ( int A = N; --A > 0; ) {
            for ( int B = N; B > A; --B ) {
                int AB = A & B;
                if ( AB > maxAB && AB < K )
                    maxAB = AB;
            }
        }
        cout << maxAB << endl;
    }
    return 0;
}
