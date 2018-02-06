#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, si, best, worst, highs, lows;
    cin >> n; --n;
    cin >> si; best = worst = si; highs = lows = 0;
    while ( --n >= 0 ) {
        cin >> si;
        if ( si > best )
            best = si, ++highs;
        else if ( si < worst )
            worst = si, ++lows;
    }
    cout << highs << ' ' << lows << endl;
    return 0;
}
