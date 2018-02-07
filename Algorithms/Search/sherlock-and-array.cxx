#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool has_potato ( vector<int> &A ) {
    auto l = begin(A), r = end(A) - 1; int left = 0, right = 0;
    while ( l != r ) {
        if ( left <= right )
            left += *l++;
        else
            right += *r--;
    }
    return left == right;
}

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        int n; cin >> n;
        vector<int> A (n); for ( int &i : A ) cin >> i;
        cout << ( has_potato (A) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
