#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    int type, counts[6] = { 0, };
    while ( --n >= 0 ) cin >> type, ++counts[type];
    int commonType;
    for ( int t = 1; t <= 5; ++t )
        if ( counts[t] > counts[0] )
            counts[0] = counts[t], commonType = t;
    cout << commonType << endl;
    return 0;
}
