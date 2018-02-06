#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t; while ( --t >= 0 ) {
        string s; cin >> s;
        int deletions = 0;
        for ( int i = s.length(), c, last = 'X'; --i >= 0; )
            if ( ( c = s[i] ) == last )
                ++deletions;
            else
                last = c;
        cout << deletions << endl;
    }
    return 0;
}
