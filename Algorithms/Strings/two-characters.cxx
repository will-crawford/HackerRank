#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LetterCount = pair<int, char>;
using LetterCounts = vector<LetterCount>;

void DropAdjacent ( vector<char> &s, LetterCounts &letters ) {
    decltype( adjacent_find ( begin(s), end(s) ) ) a;
    while ( ( a = adjacent_find ( begin(s), end(s) ) ) != end(s) ) {
        char c = *a;
        s.erase( remove( begin(s), end(s), c ), end(s) );
        letters.erase(
            find_if( begin(letters), end(letters), [=] ( const LetterCount &lc ) { return lc.second == c; } )
        );
    }
}

bool HasAdjacent ( vector<char> &s ) { auto a = adjacent_find( begin(s), end(s) ); return a != end(s); }

int FindBest ( vector<char> &s, LetterCounts &letters ) {
    if ( s.size() < 2 || letters.size() < 2 )
        return 0;
    int hwm = 0;
    for ( auto a = begin(letters); a != end(letters) && a->first >= ( hwm + 1 ) / 2; ++a ) {
        for ( auto b = a; ++b != end(letters) && a->first + b->first > hwm && a->first - b->first <= 1; ) {
            vector<char> t; copy_if (
                begin(s), end(s), back_inserter(t),
                [=] (const char &c) { return c == a->second || c == b->second; }
            );
            if ( !HasAdjacent(t) ) { hwm = t.size(); break; }
        }
    }
    return hwm;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n; cin >> ws; vector<char> s (n); vector<LetterCount> letters;
    {
        int counts['z'+1] = { 0, }; for ( char &c : s ) { cin.get(c); ++counts[c]; }
        for ( int c = 'a'; c <= 'z'; ++c ) if ( counts[c] ) letters.emplace_back( counts[c], c );
        sort ( begin(letters), end(letters), greater<>() );
    }
    DropAdjacent ( s, letters );
    cout << FindBest ( s, letters ) << endl;
    return 0;
}
