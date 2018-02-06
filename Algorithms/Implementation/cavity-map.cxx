#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector< string > rows (n);
    for ( auto &r : rows ) cin >> r;
    for ( int last = n - 1, i = 0; i < n; ++i ) {
        string &row = rows[i];
        for ( int j = 0; j < n; ++j ) {
            char c = row[j];
            cout << (
                        i && i != last && j && j != last
                     && c > rows[i-1][j] && c > row[j-1] && c > row[j+1] && c > rows[i+1][j]
                ? 'X' : c
            );
        }
        cout << endl;
    }
    return 0;
}
