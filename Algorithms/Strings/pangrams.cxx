#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s; getline ( cin, s );
    bool seen [ 'Z' + 1 ] = { false, };
    for ( const char &c : s ) seen[ c & ~0x20 ] = true;
    for ( int c = 'A'; c <= 'Z'; ++c ) if ( !seen[c] ) { cout << "not "; break; }
    cout << "pangram" << endl;
    return 0;
}
