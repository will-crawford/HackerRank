#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    vector<int> A (N); for ( int &i : A ) cin >> i;
    sort ( begin(A), end(A) );
    int epsilon = numeric_limits<int>::max();
    for ( auto i = begin(A), last = end(A) - 1; i != last; ++i )
        epsilon = min( epsilon, i[1] - i[0] );
    for ( auto i = begin(A), last = end(A) - 1; i != last; ++i )
        if ( i[1] - i[0] == epsilon )
            cout << i[0] << ' ' << i[1] << ' ';
    cout << endl;
    return 0;
}
