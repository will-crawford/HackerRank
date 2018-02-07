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

void insertionSort ( vector<int> &a ) {
    if ( a.size() < 2 )
        return;
    for ( auto i = begin(a); ++i != end(a); ) {
        int insertee = *i, tmp; auto j = i;
        while ( j != begin(a) && ( tmp = j[-1] ) > insertee ) *j-- = tmp;
        *j = insertee; cout << a << endl;
    }
}

int main() {
    int s; cin >> s;
    vector<int> ar (s); for ( int &i : ar ) cin >> i;
    insertionSort (ar);
    return 0;
}
