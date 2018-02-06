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
        cout << ( ( 1UL << ( (N + 3 ) / 2 ) ) - ( 1 + ( N & 1 ) ) ) << endl;
    }
    return 0;
}
