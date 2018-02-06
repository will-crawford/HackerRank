#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int counts [100]; fill ( begin(counts), end(counts), 0 );
    for ( int i = 0; i < n; ++i ) { int tmp; cin >> tmp; ++counts[ int( tmp % 100 ) ]; }
    cout << ( n - * max_element ( begin(counts), end(counts) ) ) << endl;
    return 0;
}
