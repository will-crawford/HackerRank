#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

ostream &operator<< (ostream &os, vector<int> &v) {
    os << '{'; auto l = begin(v), r = end(v); while ( l != r ) os << ' ' << *l++; return os << " }";
}
#define D(e) #e " = " << (e)

int main() {
    vector<int> counts (26, 0); int unique = 0, total = 0;
    for ( char c; ( cin.get(c) && c != '\n' ); ++total )
        if ( ! counts[ c - 'a' ]++ )
            ++unique;
    counts.erase(
        partition ( begin(counts), end(counts), bind( not_equal_to<>(), 0, _1 ) ),
        end(counts)
    );
    sort ( begin(counts), end(counts), greater<>() );
    cerr << D(counts) << endl;
    auto equal = [] (int value) { return bind( equal_to<>(), value, _1 ); };
    bool valid =
        total % unique < 2 && all_of( begin(counts) + 1, end(counts), equal( counts[0] - total % unique ) )
     || counts.back() == 1 && all_of( begin(counts) + 1, end(counts) - 1, equal( counts[0] ) )
    ;
    cout << ( valid ? "YES" : "NO" ) << endl;
    return 0;
}
