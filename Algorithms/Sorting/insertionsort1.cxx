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
    auto i = end(a); int insertee = *--i, tmp;
    while ( i != begin(a) && ( tmp = i[-1] ) > insertee ) { *i-- = tmp; cout << a << endl; }
    *i = insertee; cout << a;
}

int main() {
    int Size; cin >> Size;
    vector<int> Arr (Size); for ( int &i : Arr ) cin >> i;
    insertionSort (Arr);
    return 0;
}
