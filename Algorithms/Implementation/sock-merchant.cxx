#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> counts (100, 0);
    for ( int c, i = 0; i < n; ++i ) { cin >> c; ++counts[ c - 1 ]; }
    int total = 0;
    for ( int i : counts )
        total += i / 2;
    cout << total << endl;
    return 0;
}
