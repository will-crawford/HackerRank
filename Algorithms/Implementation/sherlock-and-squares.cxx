#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T;
    while ( --T >= 0 ) {
        int A, B; cin >> A >> B;
        int count = 0;
        for ( int i = floor(sqrt(A - 1)), square = i * i; ( square += 2 * ++i - 1 ) <= B; )
            ++count;
        cout << count << endl;
    }
    return 0;
}
