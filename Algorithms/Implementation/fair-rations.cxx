#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> B (N); for ( auto &i : B ) cin >> i;
    int loaves = 0;
    for ( int i = 0; i < N - 1; ++i )
        if ( B[i] & 1 )
            ++B[i], ++B[i+1], loaves += 2;
        
    ( B.back() & 1 ? ( cout << "NO" ) : ( cout << loaves ) ) << endl;
    return 0;
}
