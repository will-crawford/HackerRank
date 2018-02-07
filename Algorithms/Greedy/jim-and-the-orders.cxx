#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector<pair<int,int>> orders; for ( int i = 1, t, d; i <= n; ++i ) { cin >> t >> d; orders.emplace_back( t + d, i ); }
    sort( begin(orders), end(orders) ); for ( auto &p : orders ) cout << p.second << ' '; cout << endl;
    return 0;
}
