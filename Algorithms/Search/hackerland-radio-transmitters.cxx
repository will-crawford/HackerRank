#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline vector<int>::iterator skip (vector<int>::iterator begin, vector<int>::iterator end, int k) {
    vector<int>::iterator next = begin, middle;
    int limit = *next + k;
    if (++next == end || *next > limit) return next;
    for (;;) {
        middle = next;
        if (++next == end) return next;
        if (*next > limit) break;
    }
    limit = *middle + k;
    while (*next <= limit && ++next != end)
        ;
    return next;
}

inline void needed (int n, int k, vector<int> &x, int &count) {
    vector<int>::iterator next = begin(x);
    do ++count; while ( ( next = skip(next, end(x), k) ) != end(x) );
}

inline int needed (int n, int k, vector<int> &x) { int count = 0; needed(n, k, x, count); return count; }

int main() {
    int n, k; cin >> n >> k; vector<int> x (n); for ( auto &xi : x ) cin >> xi; sort( begin(x), end(x) );
    cout << needed(n, k, x) << endl;
    return 0;
}
