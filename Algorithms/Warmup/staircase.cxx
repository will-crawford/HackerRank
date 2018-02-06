#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; cin >> N;
    vector<char> line (N += 2, ' '); line[--N] = '\0'; line[--N] = '\n';
    while ( --N >= 0 ) {
        line[N] = '#'; cout << line.data();
    }
    return 0;
}
