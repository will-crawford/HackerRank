#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline int NextInt () { int i; cin >> i; return i; }

int main() {
    int N; cin >> N;
    vector<int> A (1000, 0); for ( int n = N; --n >= 0; ) ++A[ NextInt() - 1 ];
    vector<int> B (1000, 0); for ( int n = N; --n >= 0; ) ++B[ NextInt() - 1 ];
    int matches = 0;
    for ( int n = 1000; --n >= 0; ) matches += min( A[n], B[n] );
    if ( matches == N ) --matches; else ++matches;
    cout << matches << endl;
    return 0;
}
