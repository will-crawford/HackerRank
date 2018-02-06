#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string S; cin >> S;
    int mismatches = 0;
    for ( auto sp = begin(S); sp != end(S); sp += 3 ) {
        if ( sp[0] != 'S' ) ++ mismatches;
        if ( sp[1] != 'O' ) ++ mismatches;
        if ( sp[2] != 'S' ) ++ mismatches;
    }
    cout << mismatches << endl;
    return 0;
}
