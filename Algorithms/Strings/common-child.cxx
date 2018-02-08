#include <cmath>
#include <cstdio>
#include <array>
#include <vector>
#include <iostream>
//#include <utility>
#include <algorithm>
#include <functional>
using namespace std;

#define AS_LAMBDA(func) [&](auto&&... args) -> decltype(auto) { return func(std::forward<decltype(args)>(args)...); }

ostream &operator<< ( ostream &os, vector<int> &v ) {
    os << '{';
    for ( auto i : v ) os << ' ' << i;
    return os << " }";
}

int common_child (string a, string b) {
// find common letters (and keep a count of each, per string, in the process)
    array<int, 26> counts, aCounts, bCounts;
    aCounts.fill(0); for (char &c : a) ++aCounts[c-'A'];
    bCounts.fill(0); for (char &c : b) ++bCounts[c-'A'];
    transform ( begin(aCounts), end(aCounts), begin(bCounts), begin(counts), AS_LAMBDA(std::min) );
// drop all unshared letters from both strings, as they wouldn't be useful anyway
    auto not_common = [&] (char c) -> bool { return !counts[c-'A']; };
    a.erase( remove_if( begin(a), end(a), not_common ), end(a) ); if (a.empty()) return 0;
    b.erase( remove_if( begin(b), end(b), not_common ), end(b) ); if (b.empty()) return 0;
    cerr << "a = \"" << a << "\", b = \"" << b << "\"\n";
// make a matrix of best child lengths, starting from the end
    int A = a.length(), B = b.length();
    vector< vector<int> > best ( A + 1, vector<int> (B + 1, 0) );
    for ( int i = A; --i >= 0; ) {
        char ac = a[i];
        for ( int j = B; --j >= 0; ) {
            char bc = b[j];
            best[i][j] = max( max( best[i+1][j], best[i][j+1] ), best[i+1][j+1] + (bc == ac) );
        }
    }
    return best[0][0];
}

int main() {
    string a, b; cin >> a >> b;
    cout << common_child(a, b) << endl;
    return 0;
}
