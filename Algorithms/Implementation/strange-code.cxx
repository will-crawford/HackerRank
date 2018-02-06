
/* case in point, I've forgotten completely why I did this */

/* my final submission */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int64_t s, t; cin >> t;
    for ( s = 4; s <= t; s = ( s | 1 ) << 1 )
        ;
    cout << ( s - t ) << endl;
    return 0;
}

#if 0

/* previous attempt (you'll notice the last one is just a slight optimisation) */

int main() {
    int64_t s, t; cin >> t;
    for ( s = 4; s <= t; s = ( s << 1 ) + 2 )
        ;
    cout << ( s - t ) << endl;
    return 0;
}

/* and the one before that */

int main() {
    uint64_t t; cin >> t;
    uint64_t a = 0; while ( a < t ) a = a * 2 + 3;
    cout << ( a - t + 1 ) << endl;
    return 0;
}

#endif
