#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s; int words = 1;
    auto p = begin(s); if ( p != s.end() ) while ( ++p != s.end() ) if ( isupper(*p) ) ++words;
    cout << words << endl;
    return 0;
}
