#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool maximize_palindrome ( string &s, int k ) {
    vector<bool> b (s.length(), false);
    for ( int l = 0, r = s.length() - 1; l < r; ++l, --r ) {
        if ( s[l] != s[r] ) {
            if (!k)
                return false;
            if ( s[l] < s[r] )
                s[l] = s[r], b[l] = true;
            else
                s[r] = s[l], b[r] = true;
            --k;
        }
    }
    for ( int l = 0, r = s.length() - 1; k && l <= r; ++l, --r ) {
        if ( s[l] < '9' && ( b[l] || b[r] || k > 1 ) ) {
            s[l] = '9'; if (!b[l]) --k;
            s[r] = '9'; if (!b[r]) --k;
        }
    }
    if ( k && s.length() & 1 )
        s[ s.length() / 2 ] = '9';
    return true;
}

string & check_palindrome ( string &s, int k ) {
    if ( ! maximize_palindrome (s, k) )
        s = "-1";
    return s;
}

int main() {
    int n, k; cin >> n >> k >> ws;
    string s; cin >> s; if ( s.length() < n ) s.insert (0, n - s.length(), '0' );
    cout << check_palindrome (s, k) << endl;
    return 0;
}
