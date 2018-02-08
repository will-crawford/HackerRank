#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

int pairs (vector<int> &n, int K) {
    int count = 0;
    auto left = begin(n), right = left, end_ = end(n);
    int wanted;
    for ( ++right; ( right = find_if( right, end_, bind( greater_equal<>(), _1, wanted = *left + K ) ) ) != end_; ++left )
        if ( wanted == *right )
            ++count;
    return count;
}

int main() {
    int N, K; cin >> N >> K;
    vector<int> n (N); for ( auto &i : n ) cin >> i;
    sort (begin(n), end(n));
    cout << pairs(n, K) << endl;
    return 0;
}
