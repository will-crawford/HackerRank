#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int changes (const string &s) {
    int l = s.length();
    if (l & 1) return -1;
    int m = l >> 1;
    int counts[26] = { 0, };
    int i = 0;
    for ( ; i < m; ++i ) ++counts[ s[i] - 'a' ];
    for ( ; i < l; ++i ) --counts[ s[i] - 'a' ];
    int c = 0;
    for ( const int i : counts )
        if ( i > 0 )
            c += i;
    return c;
}

int main() {
    ios_base::sync_with_stdio (false);
    int T; cin >> T;
    string s; getline (cin, s);
    while ( --T >= 0 ) {
        getline (cin, s);
        cout << changes (s) << endl;
    }
    return 0;
}
