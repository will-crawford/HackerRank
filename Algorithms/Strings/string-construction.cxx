#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n; while ( --n >= 0 ) {
        string s; cin >> s; int32_t letters = 0; int cost = 0;
        for ( char c : s ) { int bit = 1 << ( c - 'a' ); if ( !( letters & bit ) ) letters |= bit, ++cost; }
        cout << cost << endl;
    }
    return 0;
}
