#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

using track_t = pair< int, pair< int, int > >;

void combine ( vector<track_t> &tracks ) {
    if ( tracks.size() < 2 )
        return;
    sort( begin(tracks), end(tracks) );
    for ( auto i = end(tracks); --i != begin(tracks); ) {
        track_t &right = i[0], &left = i[-1];
        if ( left.first != right.first )
            continue;
        auto &lr = left.second, &rr = right.second;
        // half-open range means adjacent ranges have overlapping co-ordinate
        if ( rr.first > lr.second )
            continue;
        // combine ranges
        // the second one might be completely subsumed by the first ...
        if ( rr.second > lr.second )
            lr.second = rr.second;
        i = tracks.erase(i);
    }
}

inline int area ( pair< int, int > range ) { return range.second - range.first; }

int64_t area ( vector<track_t> &tracks ) {
    return accumulate(
        begin(tracks), end(tracks), int64_t(0),
        [] ( int64_t sigma, const track_t & track ) -> int64_t { return sigma + area(track.second); }
    );
//    int64_t a = 0;
//    for ( auto &track : tracks )
//        a += area(track);
//    return a;
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector< pair< int, pair<int, int> > > tracks;
    while ( --k >= 0 ) {
        int r, c1, c2; cin >> r >> c1 >> c2;
        tracks.emplace_back( track_t { r - 1, { c1 - 1, c2 /* - 1 */ } } ); // extend to half-open range (see later)
    }
    combine(tracks);
    cout << ( int64_t(n) * m - area(tracks) ) << endl;
    return 0;
}
