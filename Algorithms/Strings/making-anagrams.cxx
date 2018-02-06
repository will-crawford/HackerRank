#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string a, b; cin >> a >> b;
    int ac[26] = { 0, }, bc[26] = { 0, };
    for ( char c : a ) ++ac[ c - 'a' ];
    for ( char c : b ) ++bc[ c - 'a' ];
    int d = 0;
    for ( int n = 0; n < 26; ++n )
        d += abs( bc[n] - ac[n] );
    cout << d << endl;
    return 0;
}
