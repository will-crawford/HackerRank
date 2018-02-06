#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main() {
    string date; getline(cin, date);
    long h = strtol ( &date[0], 0, 10 ) % 12;
    if ( date.length() > 8 ) {
        if ( !strncmp ( &date[8], "PM", 2 ) )
            h += 12;
        date.resize(8);
    }
    cout << setw(2) << setfill('0') << h << ( date.c_str() + 2 ) << endl;
    return 0;
}
