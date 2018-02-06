#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_funny ( string &S ) {
    for ( int l = 0, r = S.length() - 1, m = r / 2; l < m; ) {
        char lc = S[l], rc = S[r];
        if ( abs( S[++l] - lc ) != abs( S[--r] - rc ) )
            return false;
    }
    return true;
}

int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        string S; cin >> S;
        if ( !is_funny(S) ) cout << "Not ";
        cout << "Funny" << endl;
    }
    return 0;
}
