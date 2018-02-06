#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s; getline (cin, s);
    long n; cin >> n;
    size_t l = s.length(), p = n % l, fullRepetitions = n / l;
    auto start = begin(s), partial = start + p, finish = end(s);
    size_t remainder = count ( start, partial, 'a' ),
        all = remainder + count ( partial, finish, 'a' );
    cout << ( remainder + all * fullRepetitions ) << endl;
    return 0;
}
