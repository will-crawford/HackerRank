#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int Da, Ma, Ya, De, Me, Ye; cin >> Da >> Ma >> Ya >> De >> Me >> Ye;
    cout << (
        Ya > Ye ? 10000 : Ya < Ye ? 0 :
        Ma > Me ? 500 * ( Ma - Me ) : ( Ma < Me ) ? 0 :
        Da > De ? 15 * ( Da - De ) :
        0
    ) << endl;
    return 0;
}
