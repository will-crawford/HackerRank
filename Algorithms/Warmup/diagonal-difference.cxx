#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    vector< vector<int> > M ( N, vector<int> (N) );
    for ( int i = 0; i < N; ++i )
        for ( int j = 0; j < N; ++j )
            cin >> M[i][j];
    int primary = 0, secondary = 0;
    for ( int i = 0; i < N; ++i )
        primary += M[i][i], secondary += M[i][N-1-i];
    cout << abs( primary - secondary ) << endl;
    return 0;
}
