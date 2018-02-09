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

int insertionSort ( vector<int> &a ) {
    int shifts = 0;
    if ( a.size() > 1 ) {
        for ( auto i = begin(a); ++i != end(a); ) {
            int insertee = *i, tmp; auto j = i;
            while ( j != begin(a) && ( tmp = j[-1] ) > insertee ) *j-- = tmp, ++shifts;
            *j = insertee;
        }
    }
    return shifts;
}

pair<int,int> partition ( vector<int> &a, int left, int right ) {
    int swaps = 0, pivot = a[right], i = left;
    for ( int j = left; j < right; ++j )
        if ( a[j] < pivot )
            swap( a[i++], a[j] ), ++swaps;
    swap( a[i], a[right] ), ++swaps;
    return { i, swaps };
}

int quickSort ( vector<int> &a, int left, int right ) {
    if ( left < right ) {
        auto x = partition( a, left, right );
        int p = x.first, shifts = x.second;
        return shifts + quickSort( a, left, p - 1 ) + quickSort( a, p + 1, right );
    } else
        return 0;
}

int main() {
    int n; cin >> n;
    vector<int> a (n); generate( begin(a), end(a), [] () { int i; cin >> i; return i; } );
    vector<int> b = a;
    cout << insertionSort( b ) - quickSort( a, 0, a.size() - 1 ) << endl;
    return 0;
}
