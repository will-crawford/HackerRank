#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, K; string S; cin >> N; cin >> ws; S.resize(N); cin.read( &S[0], N ); cin >> K;
    for ( char &c : S ) {
        char offset = ( c & char(~0x20) ) - 'A';
        if ( isalpha (c) ) c += ( offset + K ) % 26 - offset;
    }
    cout << S << endl;
    return 0;
}
