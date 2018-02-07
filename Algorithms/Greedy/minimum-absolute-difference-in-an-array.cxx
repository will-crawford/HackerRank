#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> A (n); while ( --n >= 0 ) cin >> A[n];
    sort ( begin(A), end(A) );
    int result;
    for ( n = A.size() - 1, result = A[n] - A[n-1]; --n; result = min( result, A[n] - A[n-1] ) )
        ;
    cout << result << endl;
    return 0;
}
