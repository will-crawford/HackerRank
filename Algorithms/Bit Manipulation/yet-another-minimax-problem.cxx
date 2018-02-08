#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>
using namespace std;

using I = uint32_t;
using VI = vector<I>;
using VII = VI::iterator;

const int MAX = numeric_limits<I>::max();
const int MAX_BIT = ~( MAX >> 1 );

inline bool HasBit ( const I &i, I bit ) { return i & bit; }
struct has_bit {
    I bit;
    has_bit (I i) : bit(i) {}
    bool operator()(const I &i) { return HasBit(i, bit); }
};

struct Range {
    VII left, right;
    Range ( VII l, VII r ) : left(l), right(r) {}
    Range ( VI &v ) : left(begin(v)), right(end(v)) {}
    bool empty () { return left == right; }
    size_t size () { return right - left; }
    VII find_partition (I bit) { return find_if ( left, right, has_bit{bit} ); }
};

ostream & operator<< ( ostream &os, Range &r ) {
    os << "{";
    auto i = r.left;
    if ( i != r.right ) {
        os << " " << *i;
        while ( ++i != r.right )
            os << ", " << *i;
    }
    return os << " }";
};

I BestOf ( I single, Range r ) {
    I result = MAX, x;
    for ( VII i = r.left; i != r.right; ++i )
        if ( ( x = single ^ *i ) < result )
            result = x;
    return result;
}

I BestSubTrees ( Range r1, Range r2, I bit, I resultSoFar ) {
    if ( r1.empty() || r2.empty() )
        return MAX;

    I nextBit = bit >> 1;
    if (!nextBit)
        return resultSoFar;

    if ( r1.size() == 1 )
        return BestOf ( *r1.left, r2 );
    else if ( r2.size() == 1 )
        return BestOf ( *r2.left, r1 );

    VII p1 = r1.find_partition (nextBit), p2 = r2.find_partition (nextBit);
    Range r1l ( r1.left, p1 ), r1r ( p1, r1.right ), r2l ( r2.left, p2 ), r2r ( p2, r2.right );
    I same = min (
        BestSubTrees ( r1l, r2l, nextBit, resultSoFar ),
        BestSubTrees ( r1r, r2r, nextBit, resultSoFar )
    );
    return same != MAX ? same : min (
        BestSubTrees ( r1l, r2r, nextBit, resultSoFar | bit ),
        BestSubTrees ( r1r, r2l, nextBit, resultSoFar | bit )
    );
}

int main() {
    int n; cin >> n;
    vector<I> a (n); for ( int i = n; --i >= 0; ) cin >> a[i];
    sort ( begin(a), end(a) ); a.erase( unique( begin(a), end(a) ), end(a) );
    Range r (a);
    I bit = a.back();
    for ( I next; ( next = bit & ( bit - 1 ) ); bit = next ) ;
    while ( bit && !( ( a.back() & bit ) ^ ( a.front() & bit ) ) )
        bit >>= 1;
    if (!bit) {
        cout << 0 << endl;
    } else {
        VII middle = r.find_partition( bit );
        cout << BestSubTrees ( Range( r.left, middle ), Range( middle, r.right ), bit, bit ) << endl;
    }
    return 0;
}
