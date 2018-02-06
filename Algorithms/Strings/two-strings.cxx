#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int32_t bits_from ( istream &is ) {
    int32_t result = 0; char c; while ( is.get(c) && c != '\n' ) result |= 1 << ( c - 'a' ); return result;
}

int main() {
    int p; cin >> p; cin >> ws; while ( --p >= 0 ) {
        int32_t a = bits_from (cin), b = bits_from (cin);
        cout << ( ( a & b ) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
