#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    while ( --t >= 0 ) {
        int n, c, m; cin >> n >> c >> m;
        int chocolate = n / c;
        for ( int w = chocolate, q, r; w >= m; q = w / m, r = w % m, chocolate += q, w = q + r )
            ;
        cout << chocolate << endl;
    }
    return 0;
}
