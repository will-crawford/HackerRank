#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

#define D(e) cerr << #e " = " << (e) << endl
#define Assert(e) if ( !(e) ) throw ( "!(" #e ")!" )

using L = int64_t;
using LV = vector<L>;
const L Max32 = numeric_limits<int32_t>::max();
const L Max64 = numeric_limits<int64_t>::max();
const L HalfMax64 = ( Max64 / 2 );
const L MaxB = 100000;

inline ostream &operator<< ( ostream &o, LV &v ) {
    auto i = begin(v), j = end(v);
    if ( i != j ) {
        o << *i;
        while ( ++i != j )
            o << ' ' << *i;
    }
    return o;
}

inline bool TooBigForT ( L n ) { return n > Max32; }
inline L T( L n ) { return ( n * ( n + 1 ) ) / 2; }

inline L Min( L b ) { return T(b); }
inline bool TooBigForMax( L k, L b ) { return k >= ( HalfMax64 / b ); }
inline L Max( L k, L b ) { return ( b * ( 2 * k - b + 1 ) ) / 2; }

inline L Low( L n, L k, L b ) {
    L i = n / b;
    while ( i < k && i < n - Max( i - 1, b - 1 ) )
        ++i;
    return i;
}
inline L High( L n, L k, L b ) { return min( k, n - Min( b - 1 ) ); }

inline L rnd ( L low, L high ) {
    static random_device rd;
    static mt19937_64 g { rd() };
    L result = uniform_int_distribution<L> ( low, high ) ( g );
    D(low), D(high), D(result);
    return result;
}

inline void y ( LV &solution, L n, L k, L b ) {
    Assert( b <= k );
    Assert( n >= Min(b) );

    while ( b ) {
        //L high = High ( n, k, b ), choice = TooBigForMax ( k, b ) ? high : rnd( Low ( n, k, b ), high );
        L choice = High ( n, k, b );
        solution.push_back(choice);
        n -= choice, k = choice - 1, --b;
    }
    if ( n )
        throw "dieee";
}

inline void x ( LV &solution, L n, L k, L b ) {
    try { y ( solution, n, k, b ); } catch (...) { solution.clear(); }
    if ( solution.empty() )
        solution.push_back(-1);
}

int main() try {
    int t; cin >> t;
    while ( --t >= 0 ) {
        L n, k, b; cin >> n >> k >> b;
        LV solution; x ( solution, n, k, b ); cout << solution << endl;
    }
    return EXIT_SUCCESS;
} catch (const char *e) { cerr << "Failed assertion: " << e << endl; return EXIT_FAILURE; }
