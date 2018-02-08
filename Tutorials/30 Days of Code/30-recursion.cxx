#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long factorial ( long n ) {
    return n > 1 ? n * factorial ( n - 1 ) : 1;
}

int main() {
    long N; cin >> N;
    cout << factorial (N) << endl;
    return 0;
}
