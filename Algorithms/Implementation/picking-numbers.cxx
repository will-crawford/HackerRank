#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    int counts[101] = { 0, }; while ( --n >= 0 ) { int i; cin >> i; ++counts[i]; }
    int maximum = 0; for ( int i = 0; i < 100; ++i ) {
        int total = counts[i] + counts[i+1];
        if ( total > maximum ) maximum = total;
    }
    cout << maximum << endl;
    return 0;
}
