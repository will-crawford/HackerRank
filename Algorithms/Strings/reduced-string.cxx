#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio (false);
    string s; cin >> s; string t; t.reserve( s.size() );
    for ( char c : s )  if ( t.size() && c == t.back() ) t.pop_back(); else t.push_back(c);
    ( t.size() ? cout << t : cout << "Empty String" ) << endl;
    return 0;
}
