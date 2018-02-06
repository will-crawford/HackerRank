#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    vector<int> sticks (N); for ( auto & i : sticks ) cin >> i;
    sort ( begin(sticks), end(sticks), greater<>() );
    while ( !sticks.empty() ) {
        size_t n = sticks.size();
        cout << n << endl;
        int cut = sticks.back();
        for ( int last = n; last != 0 && sticks[--last] <= cut; n = last )
            ;
        sticks.resize (n);
        for ( int & i : sticks )
            i -= cut;
    }
    return 0;
}
