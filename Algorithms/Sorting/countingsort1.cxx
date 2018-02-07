#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline ostream &operator<< (ostream &os, vector<int> &v) {
    auto i = begin(v), j = end(v);
    if ( i != j ) {
        os << *i;
        while ( ++i != j )
            os << ' ' << *i;
    }
    return os;
}

int main() {
    int n; cin >> n;
    vector<int> counts (100, 0); while ( --n >= 0 ) { int x; cin >> x; ++counts[x]; }
    cout << counts << endl;
    return 0;
}
