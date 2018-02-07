#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int g; cin >> g; while ( --g >= 0 ) {
        int n; cin >> n; vector<int> s (n); while ( --n >= 0 ) { cin >> s[n]; }
        cout << ( accumulate( begin(s), end(s), 0, bit_xor<>() ) ? "First" : "Second" ) << endl;
    }
    return 0;
}
