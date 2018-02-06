#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ostream & operator<< ( ostream &os, vector<int> &v ) {
    auto i = begin(v);
    if ( i != end(v) ) {
        os << *i;
        while ( ++i != end(v) )
            os << ' ' << *i;
    }
    return os;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m);
    for ( int & i : A ) cin >> i;
    for ( int & i : B ) cin >> i;
    if ( n <= 0 || m <= 0 ) {
        cout << '0' << endl;
        return 0;
    }
    sort ( begin(A), end(A), greater<>() );
    sort ( begin(B), end(B), less<>() );
    vector<int> multiples (A), candidates;
// largest x must be <= the lowest member of B
    for ( ; multiples[0] <= B[0]; multiples[0] += A[0] ) {
        bool found = true;
        for ( int i = 1; i < multiples.size(); ++i ) {
            while ( multiples[i] < multiples[0] )
                multiples[i] += A[i];
            if ( multiples[i] > multiples[0] ) {
                found = false;
                break;
            }
        }
        if ( found )
            candidates.push_back( multiples[0] );
//        cerr << multiples << endl;
    }
//    cerr << candidates << endl;
    int count = 0;
    for ( auto i : candidates ) {
        bool found = true;
        for ( auto j : B ) {
            if ( ( j % i != 0 ) ) {
                found = false;
                break;
            }
        }
        if ( found )
            ++count;
    }
    cout << count << endl;
    return 0;
}
