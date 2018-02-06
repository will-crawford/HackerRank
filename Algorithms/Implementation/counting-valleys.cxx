#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main() {
    int n, height = 0, valleys = 0; cin >> n >> ws;
    for ( char c; --n >= 0; ) {
        cin.get(c);
        if ( c == 'D' ) --height; else if ( !++height ) ++ valleys;
    }
    cout << valleys << endl;
    return 0;
}
