#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int N; cin >> N;
        int threes = N % 3, fives = N - threes;
        while ( threes % 5 )
            threes += 3, fives -= 3;
        if ( fives < 0 )
            cout << -1 << endl;
        else
            cout << setfill('5') << setw(N) << string(threes, '3') << endl;
    }
    return 0;
}
