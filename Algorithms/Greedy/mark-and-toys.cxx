#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<int> prices (n); for ( int i = n; --i >= 0; cin >> prices[i] ) ;
    sort( begin(prices), end(prices) );
    int toys = 0;
    for ( int p : prices ) if ( p > k ) break; else k -= p, ++toys;
    cout << toys << endl;
    return 0;
}
