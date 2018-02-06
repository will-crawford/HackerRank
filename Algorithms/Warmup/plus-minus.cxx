#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    int below = 0, equal = 0, above = 0;
    for ( int a, i = N; --i >= 0; ) {
        cin >> a;
        if ( a < 0 ) ++below; else if ( a > 0 ) ++above; else ++equal;
    }
    cout << double(above) / N << endl << double(below) / N << endl << double(equal) / N << endl;
    return 0;
}
