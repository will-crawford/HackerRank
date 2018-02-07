#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int V, n; cin >> V >> n; vector<int> ar (n); for ( auto &i : ar ) cin >> i;
    cout << ( find ( begin(ar), end(ar), V ) - begin(ar) ) << endl;
    return 0;
}
