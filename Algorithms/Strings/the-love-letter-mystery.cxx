#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T; cin >> T; while ( --T >= 0 ) {
        string s; cin >> s; int changes = 0;
        for ( int l = 0, r = s.length(), m = r / 2; l < m; changes += abs( s[l++] - s[--r] ) )
            ;
        cout << changes << endl;
    }
    return 0;
}
