#include <cmath>
#include <cstdio>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    array<int64_t, 5> input;
    for ( int i = 0; i < 5; cin >> input[i++] )
        ;
    auto extremes = minmax_element ( begin(input), end(input) );
    auto total = accumulate ( begin(input), end(input), 0L );
    cout << ( total - *extremes.second ) << ' ' << ( total - *extremes.first ) << endl;
    return 0;
}
