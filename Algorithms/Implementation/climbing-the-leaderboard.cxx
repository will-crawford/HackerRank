#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n; vector<int> scores (n); for ( auto &i : scores ) cin >> i;
    auto last = unique( begin(scores), end(scores) ); scores.resize( last - begin(scores) );
    int m, alice, aliceRank = scores.size(); cin >> m;
    while ( --m >= 0 ) {
        cin >> alice;
        while ( aliceRank && scores[aliceRank - 1] <= alice )
            --aliceRank;
        cout << aliceRank + 1 << endl;
    }
    return 0;
}
