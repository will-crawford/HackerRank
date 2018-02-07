#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> ar (n); for ( int &i : ar ) cin >> i;
    auto median = begin(ar) + n / 2; nth_element( begin(ar), median, end(ar) );
    cout << *median << endl;
    return 0;
}
