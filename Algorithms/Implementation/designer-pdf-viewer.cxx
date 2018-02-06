#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    array< int, 26 > heights;
    for ( auto & i : heights )
        cin >> i;
    string word; cin >> word;
    int height = 0;
    for ( char c : word )
        height = max ( height, heights[ c - 'a' ] );
    cout << ( height * word.length() ) << endl;
    return 0;
}
