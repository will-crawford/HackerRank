#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
// after re-reading the input definition
    int T; cin >> T;
    while (--T >= 0) {
        int N; cin >> N;
    // after looking at Wikipedia ...
        int a; cin >> a;
        int bestToHere = a, best = a, disjoint = a;
        while ( --N > 0 ) 
            cin >> a, bestToHere = max ( a, bestToHere + a ), best = max ( best, bestToHere ), disjoint = max ( disjoint, max ( disjoint + a, a ) );
        cout << best << ' ' << disjoint << endl;
    }
    return 0;
}
