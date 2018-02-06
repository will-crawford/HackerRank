#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline void MaybeSet ( vector<int> &v, int p, int i ) { if ( p && i && !v[p] ) v[p] = i; }

int main() {
    int n; cin >> n;
// (y-1) -> p(y)
    vector<int> py (n);
    for ( auto &p : py ) cin >> p;
// p(y) -> y
    vector<int> prepy (51, 0);
    for ( int i = 0; i < n; ++i ) MaybeSet( prepy, py[i], i+1 );
// p(p(y)) -> y
    vector<int> preppy (51, 0);
    for ( int i = 1; i <= 50; ++i ) MaybeSet( preppy, py[i-1], prepy[i] );
// now print out pre-pre-images of 1..n
    for ( int i = 1; i <= n; ++i )
        cout << preppy[i] << endl;
    return 0;
}
