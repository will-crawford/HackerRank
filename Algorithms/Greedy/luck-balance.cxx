#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

inline int sum ( vector<int> &v, int start, int finish )
    { return accumulate ( begin(v) + start, begin(v) + finish, 0 ); }

int main() {
    int N, K; cin >> N >> K; int balance = 0; vector<int> important;
    while ( --N >= 0 )
        { int Li, Ti; cin >> Li >> Ti; if ( Ti ) important.push_back ( Li ); else balance += Li; }
    int Ni = important.size(); if ( Ni ) {
        sort ( begin(important), end(important), greater<>() );
        auto left = begin(important), middle = left + min (K, Ni), right = end(important);
        balance = accumulate ( middle, right, accumulate ( left, middle, balance), minus<>() );
    }
    cout << balance << endl;
    return 0;
}
