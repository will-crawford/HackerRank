#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    vector<int> W (N); for ( int &i : W ) cin >> i; sort( begin(W), end(W) );
    int units = 0;
    for ( int i = N; --i >= 0; ++units ) {
        int w = W[i];
        while ( i > 0 && w - W[i-1] <= 4 )
            --i;
    }
    cout << units << endl;
    return 0;
}
