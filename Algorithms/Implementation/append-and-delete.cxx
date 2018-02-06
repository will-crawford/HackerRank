#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <type_traits>
using namespace std;

#define D(e) cerr << #e " = " << (e) << endl

inline bool can ( const string &s, const string &t, int k ) {
    auto sl = s.length(), tl = t.length();
    if ( sl != tl ) {
        if ( tl > sl )
            swap ( tl, sl );
        k -= ( sl - tl );
        if ( k < 0 )
            return false;
    }
    auto common = make_signed_t<decltype(tl)>(tl) - k / 2;
    if ( common <= 0 )
        return true;
    if ( k & 1 )
        return false;
    for ( int i = common; --i >= 0; )
        if ( s[i] != t[i] )
            return false;
    return true;
}

int main() {
    string s, t; int k; cin >> s >> t >> k;
    cout << ( can( s, t, k ) ? "Yes" : "No" ) << endl;
    return 0;
}
