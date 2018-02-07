#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const char * const units[] = {
    0,     "one",    "two",    "three", "four", "five", "six", "seven", "eight", "nine"
}, * const teens[] = {
    "ten", "eleven", "twelve", "thir",  0,      "fif",  0,     0,       "eigh",  0
}, * const tens[] = {
    0,     0,        "twen",   0,       "for",  0,      0,     0,       0,       0
}, * const quarters[] = { 0, "quarter", "half" };

template <typename N> N first_of ( N a, N b ) { return a ? a : b; }
template <typename N> N first_of ( N a, N b, N c ) { return a ? a : b ? b : c; }

struct number {
    int n;
    number (int n) : n (n) { }
    void operator() (ostream &os) const {
        int t = n / 10, u = n % 10;
        if ( t == 1 ) {
            os << first_of( teens[u], units[u] );
            if ( n >= 13 )
                os << "teen";
            return;
        }
        if ( t >= 2 )
            os << first_of( tens[t], teens[t], units[t] ) << "ty ";
        os << units[u];
    }
};
ostream & operator << ( ostream &os, const number &n ) { n(os); return os; }

struct minutes {
    int m;
    minutes (int m) : m (m) { }
    void operator() (ostream &os) const {
        if ( m % 15 )
            os << number(m) << ( m > 1 ? " minutes" : " minute" );
        else if (m)
            os << quarters[ m / 15 ];
    }
};
ostream & operator << ( ostream &os, const minutes &m ) { m(os); return os; }

int main() {
    int H, M; cin >> H >> M;

    const char *pastOrTo;
    if ( !M ) {
        cout << number(H) << " o' clock" << endl;
    } else {
        if ( M > 30 ) pastOrTo = "to", M = 60 - M, H = H == 12 ? 1 : H + 1; else pastOrTo = "past";
        cout << minutes(M) << ' ' << pastOrTo << ' ' << number(H) << endl;
    }
    return 0;
}
