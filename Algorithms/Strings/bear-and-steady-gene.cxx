#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline ostream &operator<< ( ostream &os, int (&a)[4] ) {
    return os << "{ " << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << " }";
}

#define DE(e) #e " = " << (e)
#define D(e) cerr << DE(e) << endl

inline int base (char c) { return ( c / 2 ) % 4; }

void find_minimum (string &s, int &minimum) {
    int N = s.length(), n = N / 4;
    int bases[4] = { 0, };
    // { A = 1, C = 3, G = 7, T = 20 } / 2 % 4 => { A = 0, C = 1, G = 3, T = 2 }
    for ( char &c : s ) ++bases[ c = base(c) ];
    bool steady = true;
    for ( int &b : bases ) if ( ( b -= n ) < 0 ) steady = false;
    if (steady) { minimum = 0; return; }
    minimum = N;
    // minimum substring can't be shorter than the number of excess bases
    int excess = 0, excessive = 0; for ( int b : bases ) if ( b > 0 ) excess += b, ++excessive;
    int subBases[4] = { 0, };  // start with longest possible and whittle it down
    bool sufficient = false;
    auto add = [&] (char b) { if ( ++subBases[b] == bases[b] ) --excessive; };
    auto drop = [&] (char b) { if ( subBases[b]-- == bases[b] ) ++excessive; };
    for ( int i = 0, j = 0, l = 0; i < N - excess; drop(s[i++]), --l ) {
        for ( ; l < minimum; add( s[j++] ), ++l ) {
            if ( l >= minimum ) break;
            else if (!excessive) { minimum = l; break; }
            else if ( j == N ) return;
        }
    }
}

int minimum_substring_length (string &s) {
    int minimum;
    find_minimum( s, minimum );
    return minimum;
}

int main() {
    int N; string s; cin >> N >> s;
    cout << minimum_substring_length(s) << endl;
    return 0;
}
