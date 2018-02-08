#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n;
    for ( int i = 1; i <= 10; ++i )
        cout << n << " x " << i << " = " << ( n * i ) << endl;
    return 0;
}
