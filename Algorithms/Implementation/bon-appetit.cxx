#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k, price, total = 0, actual, shared;
    cin >> n >> k;
    for ( int i = 0; i < n; ++i ) {
        cin >> price;
        if ( i != k )
            total += price;
    }
    actual = total / 2;
    cin >> shared;
    if ( shared == actual )
        cout << "Bon Appetit";
    else
        cout << ( shared - actual );
    cout << endl;
    return 0;
}
