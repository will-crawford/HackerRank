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

int partition ( vector<int> &a, int left, int right ) {
    int pivot = a[right];
    int i = left;
    for ( int j = left; j < right; ++j )
        if ( a[j] < pivot )
            swap( a[i++], a[j] );
    swap( a[i], a[right] );
    cout << a << endl;
    return i;
}

void quickSort ( vector<int> &a, int left, int right ) {
    if ( left < right ) {
        int p = partition( a, left, right );
        quickSort( a, left, p - 1 );
        quickSort( a, p + 1, right );
    }
}

int main() {
    int n; cin >> n;
    vector<int> a (n); generate( begin(a), end(a), [] () { int i; cin >> i; return i; } );
    quickSort( a, 0, a.size() - 1 );
    return 0;
}
