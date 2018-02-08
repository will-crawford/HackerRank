#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

const int64_t MaxLoss = numeric_limits<int64_t>::max();

int main() {
    int n; cin >> n;
    set<int64_t> prior; int64_t pi, loss, best = MaxLoss;
    cin >> pi; prior.insert(pi);
    while (--n > 0) {
        cin >> pi;
        auto i = prior.upper_bound(pi);
        if ( i != prior.end() && ( loss = *i - pi ) < best )
            best = loss;
        prior.insert( i, pi );
    }
    cout << best << endl;
    return 0;
}
