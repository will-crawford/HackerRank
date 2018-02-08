
#include <iostream>
#include <numeric>
#include <random>
using namespace ::std;

using dist = uniform_int_distribution<int>;
using generator = default_random_engine;

int main ( int, const char ** ) {
    cout << 5 << endl;
    random_device rd;
    generator g( rd() );
    for ( int t = 0, n = dist(3, 196)(g); t < 5; ++t, ++n ) {
        int k = dist(1, n - 1)(g);
        cout << n << ' ' << k << endl;
        bool cancel = !( t & 1 );
        int a0 = k - n - cancel;
        vector<int> a(n); iota( begin(a), end(a), a0 );
        for ( const auto i : a ) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
