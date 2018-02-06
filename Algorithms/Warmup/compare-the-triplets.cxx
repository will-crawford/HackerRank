#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int A[3], B[3], Alice = 0, Bob = 0;
    cin >> A[0] >> A[1] >> A[2] >> B[0] >> B[1] >> B[2];
    for ( int i = 0; i < 3; ++i )
        if ( A[i] > B[i] )
            ++Alice;
        else if ( A[i] < B[i] )
            ++Bob;
    cout << Alice << ' ' << Bob << endl;
    return 0;
}
