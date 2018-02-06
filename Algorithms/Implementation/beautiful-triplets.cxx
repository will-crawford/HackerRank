#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, d; cin >> n >> d;
    vector<int> a (n); for ( int &i : a ) cin >> i;
    int beautiful = 0;
    for ( int i = n - 2; --i >= 0; ) {
        for ( int j = n - 1; --j > i; ) {
            int Dij = a[j] - a[i];
            if ( Dij > d ) continue;
            if ( Dij < d ) break;
            for ( int k = n; --k > j; ) {
                int Djk = a[k] - a[j];
                if ( Djk > d ) continue;
                if ( Djk == d ) ++beautiful;
                break;
            }
        }
    }
    cout << beautiful << endl;
    return 0;
}
