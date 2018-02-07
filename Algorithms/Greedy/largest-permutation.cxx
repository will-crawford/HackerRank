#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

ostream & operator<< ( ostream &os, vector<int> &v ) {
    auto i = begin(v), j = end(v);
    if ( i != j ) {
        os << *i;
        while ( ++i != j )
            os << ' ' << *i;
    }
    return os;
}

int main() {
    int N, K; cin >> N >> K;
    if ( K >= N ) {
        // drain input
        cin.ignore( numeric_limits<std::streamsize>::max() );
        cout << N; while ( --N ) cout << ' ' << N;
    } else {
        vector<int> A (N), positions (N + 1);
        for ( int i = 0, n; i < N; ++i ) { cin >> n; A[i] = n; positions[n] = i; }
        for ( int i = 0; K && i < N; ++i ) {
            int desired = N - i, positionOfDesired = positions[desired];
            if ( positionOfDesired == i )
                continue;
            int currentValue = A[i];
            A[i] = desired, positions[desired] = i;
            A[positionOfDesired] = currentValue, positions[currentValue] = positionOfDesired;
            --K;
        }
        cout << A << endl;
    }
    return 0;
}
