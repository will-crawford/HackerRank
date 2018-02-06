#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, i, hwm = 0, count = 0; cin >> n; 
    while ( --n >= 0 ) { cin >> i; if ( i > hwm ) hwm = i, count = 1; else if ( i == hwm ) ++count; }
    cout << count << endl;
    return 0;
}
