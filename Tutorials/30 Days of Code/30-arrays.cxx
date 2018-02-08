#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    generate ( begin(arr), end(arr), [] () { int i; cin >> i; return i; } );
    for_each ( arr.rbegin(), arr.rend(), [] ( int i ) { cout << i << ' '; } );
    cout << endl;
    return 0;
}
