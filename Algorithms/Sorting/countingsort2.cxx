#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline ostream &operator<< (ostream &os, vector<int> &v) {
    for ( int i = 0, j = v.size(); i < j; ++i )
        for ( int n = v[i]; n; --n )
            cout << i << ' ';
    return os;
}

int main() {
    int n; cin >> n;
    vector<int> counts (100, 0); while ( --n >= 0 ) { int x; cin >> x; ++counts[x]; }
    cout << counts << endl;
    return 0;
}
