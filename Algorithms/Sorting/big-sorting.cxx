#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n >> ws; vector<string> vs (n); while ( n > 0 ) cin >> vs[--n];
    sort ( begin(vs), end(vs), [] ( const string &l, const string &r ) {
            size_t ll = l.length(), rl = r.length(); return ll < rl || ll == rl && l < r;
    } );
    for ( auto &s : vs )
        cout << s << endl;
    return 0;
}
