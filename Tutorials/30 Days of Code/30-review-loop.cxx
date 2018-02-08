#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T; cin >> T;
    string dummy; getline(cin, dummy);
    for ( int t = 0; t < T; ++t ) {
        string s; getline(cin, s);
        for ( int start = 0; start < 2; ++start ) {
            for ( int i = start; i < s.length(); i += 2 )
                cout << s[i];
            cout << ( start == 0 ? ' ' : '\n' );
        }
    }
    return 0;
}
