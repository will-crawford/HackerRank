#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, p; cin >> n >> p; n /= 2, p /= 2;
    cout << min( p, n - p ) << endl;
    return 0;
}
