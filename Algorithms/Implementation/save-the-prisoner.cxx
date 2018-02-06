#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int N, M, S; cin >> N >> M >> S;
        cout << ( ( S + M - 2 ) % N + 1 ) << endl;
    }
    return 0;
}
