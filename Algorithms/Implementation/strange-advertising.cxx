#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    int m = 2, likes = m;
    for ( int i = 1; ++i <= n; likes += ( m = ( m * 3 ) / 2 ) )
        ;
    cout << likes << endl;
    return 0;
}
