#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool ZeroMod4 ( int year ) { return !( year & 3 ); }
inline bool IsLeap ( int year ) { return ZeroMod4(year) && ( year < 1918 || year % 100 || ZeroMod4( year / 100 ) ); }

int main() {
    int year; cin >> year;
    cout << ( year == 1918 ? 26 : IsLeap(year) ? 12 : 13 ) << ".09." << year << endl;
    return 0;
}
