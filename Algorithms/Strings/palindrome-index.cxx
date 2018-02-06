#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_palindrome ( string &s, int l, int r ) {
    for ( ; l < r; ++l, --r )
        if ( s[l] != s[r] )
            return false;
    return true;
}

int check_palindrome ( string &s ) {
    for ( int l = 0, r = s.length() - 1; l < r; ++l, --r ) {
        if ( s[l] == s[r] ) continue;
        if ( is_palindrome ( s, l + 1, r ) ) return l;
        if ( is_palindrome ( s, l, r - 1 ) ) return r;
        break;
    }
    return -1;
}

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        string S; cin >> S; cout << check_palindrome (S) << endl;
    }
    return 0;
}
