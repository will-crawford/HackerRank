#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//struct IceCream { int cost, index; };
//    IceCream(int flavour, int index) : flavour(flavour), index(index) { }
using IceCream = pair <int, int>;

int binarySearch ( int left, int right, vector<IceCream> &A, int search ) {
    do {
        int middle = ( left + right + 1 ) / 2;
        if ( search < A[middle].first )
            right = middle - 1;
        else if ( search > A[middle].first )
            left = middle + 1;
        else
            return middle;
    } while ( left <= right );
    return -1;
}

int main() {
    int t; cin >> t; while ( --t >= 0 ) {
        int m, n; cin >> m >> n;
        vector<IceCream> A; for ( int i = 1; i <= n; ++i ) { int ci; cin >> ci; A.emplace_back( ci, i ); }
        sort ( begin(A), end(A) );
        for ( auto i = begin(A); i->first <= m / 2; ++i ) {
            int needed = m - i->first;
            int index = binarySearch( i - begin(A) + 1, n - 1, A, needed );
            if ( index >= 0 ) {
                int id1 = i->second, id2 = A[index].second; if ( id1 > id2 ) swap (id1, id2);
                cout << id1 << ' ' << id2 << endl;
            }
        }
    }
}
