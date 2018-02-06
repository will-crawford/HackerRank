#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    long long total = 0;
    while (N) { int i; cin >> i; total += i; --N; }
    cout << total << endl;
    return 0;
}
