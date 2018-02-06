#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a (n); for ( int &i : a ) cin >> i;
    for ( int gap = 0; ++gap < n; )
        for ( int i = 0, end = n - gap; i < end; ++i )
            if ( a[ i ] == a[ i + gap ] ) { cout << gap << endl; return 0; }
    cout << -1 << endl; return 0;
}
