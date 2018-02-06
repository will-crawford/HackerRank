#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int x1, v1, x2, v2; cin >> x1 >> v1 >> x2 >> v2;
    int gap = x2 - x1, catchup = v1 - v2;
    if ( gap < 0 ) gap = -gap, catchup - catchup;
    cout << ( ( !gap || catchup > 0 && (gap % catchup) == 0 ) ? "YES" : "NO" ) << endl;
    return 0;
}
