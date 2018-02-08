#include <cmath>
#include <cstdio>
#include <utility>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const char UNMATCHED = char(-1);

inline void insert_sorted ( string &s, char c ) {
    auto i = s.size();
    while ( i && s[i-1] > c )
        --i;
    s.insert( i, 1, c );
}

ostream & operator << ( ostream &os, pair<int,int> &p ) { return os << '(' << p.first << ", " << p.second << ')'; }
ostream & operator << ( ostream &os, vector<pair<int,int>> &vp ) {
    auto i = begin(vp), j = end(vp);
    os << '{';
    while ( i != j )
        os << ' ' << *i++;
    return os << " }";
}
ostream & operator << ( ostream &os, map<string,vector<pair<int,int>>> &msvp ) {
    for ( auto &entry : msvp )
        os << '"' << entry.first << '"' << ' ' << entry.second << endl;
    return os;
}

int sherlockAndAnagrams ( string &s ) {
//    int repeated = 0;
//    int counts[26] = { 0, };
//    for ( char &c : s )
//        if ( !counts[ c - 'a' ]++ )
//            ++repeated;
//    if (repeated < 2)
//        return 0;

//    auto is_repeated = [&] (char c) -> bool { return counts[c-'a'] != 0; };
//    while ( !is_repeated(s.back()) ) s.pop_back();
//    while ( !is_repeated(s.front()) ) s.erase(begin(s));

    map<string,vector<pair<int,int>>> strings;
    int n = s.length();
    for ( int i = 0, j; i < n; ++i ) {
//        if ( !is_repeated(s[i]) ) continue;
        string letters;
        for ( int j = i; j < n /* && is_repeated(s[j]) */; ++j ) {
//            cerr << "s[j] = '" << s[j] << '\'' << endl;
            insert_sorted( letters, s[j] );
//            cerr << "letters = \"" << letters << '"' << endl;
            strings[letters].emplace_back( i, j );
        }
    }
//    cerr << strings << endl;

    int pairs = 0;
    for ( auto &entry : strings ) {
        auto &ranges = entry.second;
        int nr = ranges.size();
        if ( nr < 2 ) continue;
//        int adjacent = 0;
//        decltype( begin(ranges) ) i, j, k;
//        for ( i = begin(ranges), k = end(ranges); ( j = next(i) ) != k; i = j ) {
//            cerr << "first = " << *i << " second = " << *j << endl;
//            if ( i->second + 1 == j->first )
//                ++adjacent;
//        }
    // total number of pairs is nCr with n = # of pairs, r = 2, PLUS same again LESS # of adjacent pairs
//        cerr << "nr = " << nr /* << ", adjacent = " << adjacent */ << endl;
        pairs += nr * ( nr - 1 ) / 2 /* - adjacent */;
    }
    return pairs;
}

int main() {
    int t; cin >> t; while ( --t >= 0 ) {
        string s; cin >> s;
        cout << sherlockAndAnagrams(s) << endl;
    }
    return 0;
}
