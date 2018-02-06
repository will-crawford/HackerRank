#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n; string s, needle = "010"; cin >> s; int changes = 0;
    for ( string::size_type p = 0, q = string::npos; ( p = s.find ( needle, p ) ) != q; p += 3, ++changes )
        ;
    cout << changes << endl;
    return 0;
}
