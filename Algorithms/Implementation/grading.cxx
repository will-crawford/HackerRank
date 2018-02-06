#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, grade;
    cin >> n;
    do {
        cin >> grade;
        if ( grade >= 38 ) { int r = grade % 5; if ( r > 2 ) grade += 5 - r; }
        cout << grade << endl;
    } while (--n);
    return 0;
}
