#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool isPalindrome ( const string &s ) {
    int counts [26] = { 0, };
    for ( const auto c : s )
        ++counts[ c - 'a' ];
    int odds = 0;
    for ( int i : counts )
        if ( i % 2 && odds++ )
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; getline( cin, s );
    cout << ( isPalindrome(s) ? "YES" : "NO" ) << endl;
    return 0;
}
