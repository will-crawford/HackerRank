#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector< vector<string> > a (100);
    int x; string s;
    for ( int i = n / 2; --i >= 0; ) { cin >> x >> s; a[x].emplace_back("-"); }
    for ( int i = n / 2; --i >= 0; ) { cin >> x >> s; a[x].emplace_back(move(s)); }
    for ( auto &sv: a )
        for ( auto &s : sv )
            cout << s << ' ';
    cout << endl;
    return 0;
}
