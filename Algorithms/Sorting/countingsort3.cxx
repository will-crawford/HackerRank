#include <cmath>
#include <cstdio>
#include <array>
#include <vector>
#include <numeric>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

inline int nextInt (istream &is) {
    int i; is >> i;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    array<int, 100> counts; counts.fill(0);
    int n; cin >> n; while (--n >= 0) ++counts[ nextInt(cin) ];
    partial_sum( begin(counts), end(counts), ostream_iterator<int>( cout, " " ) );
    return 0;
}
