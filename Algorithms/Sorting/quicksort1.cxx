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

void partition ( vector<int> &a ) {
    vector<int> left, equal, right;
    int p = a[0];
    for ( auto i : a )
        ( i < p ? left : i == p ? equal : right ).emplace_back (i);
    copy(
        begin(right), end(right), copy(
            begin(equal), end(equal), copy(
                begin(left), end(left), begin(a)
            )
        )
    );
    cout << a << endl;
}

int main() {
    int s; cin >> s;
    vector<int> ar (s); for ( int &i : ar ) cin >> i;
    partition (ar);
    return 0;
}

