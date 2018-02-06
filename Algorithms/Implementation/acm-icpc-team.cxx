#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline int combine ( vector<char> &a, vector<char> &b ) {
    int count = 0;
    for ( auto i = begin(a), j = begin(b); i != end(a); ++i, ++j )
        if ( *i || *j )
            ++count;
    return count;
}

int main() {
    int N, M; cin >> N >> M;
    vector< pair< int, vector<char> > > knowledge (N, pair< int, vector<char> > { 0, { vector<char> (M) } } );
    string dummy;
    for ( auto &row : knowledge ) {
        for ( auto &col : row.second )
            cin >> col, col -= '0', row.first += bool(col);
    }
    int hwm = 0, count = 0;
    for ( auto i = begin(knowledge), last = end(knowledge) - 1; i < last; ++i ) {
        for ( auto j = i; ++j != end(knowledge); ) {
            if ( i->first + j->first < hwm )
                continue;
            int combined = combine ( i->second, j->second );
            if ( combined > hwm )
                hwm = combined, count = 1;
            else if ( combined == hwm )
                ++count;
        }
    }
    cout << hwm << endl << count << endl;
    return 0;
}
