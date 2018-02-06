#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int N; cin >> N;
        int count = 0;
        for ( int remainder = N, digit; remainder; remainder /= 10 )
            if ( ( digit = remainder % 10 ) && !( N % digit ) )
                ++count;
        cout << count << endl;
    }
    return 0;
}
