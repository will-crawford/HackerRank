#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int swaps ( vector<int> &p ) {
    int n = p.size(), s = 0;
    vector<int> pp(n); for ( int i = 0; i < n; ++i ) pp[p[i]] = i;
    for ( int i = 0, replacing; i < n; ++i ) {
        if ( ( replacing = p[i] ) != i ) {
            ++s;
            swap( p[i], p[pp[i]] );
            swap( pp[i], pp[replacing] );
        }
    }
    return s;
}

void position_sort ( vector<int> &a, vector<int> &p ) {
    auto cmp = [&] (int x, int y) { return a[x] < a[y]; };
    sort( begin(p), end(p), cmp );
}

int main() {
    int n; cin >> n;
    vector<int> a(n); for (auto &i : a) cin >> i;
    vector<int> p(n); iota( begin(p), end(p), 0 ); position_sort( a, p );
    vector<int> rp(n); reverse_copy( begin(p), end(p), begin(rp) );
    cout << min( swaps(p), swaps(rp) );
    return 0;
}
