#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int N, M; cin >> N >> M;
        cout << ( ( M > 1 && N & 1 ) ? 1 : 2 ) << endl;
    }
    return 0;
}
