#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    bool loses[18][18] = { false, };
    {
        for ( int y = 1, x = 1; ; ) {
            loses[y][x] = ( x < 2 && y < 2 )
                    || !( loses[y-2][x-1] || loses[y-2][x+1] || loses[y-1][x-2] || loses[y+1][x-2] );
            if ( !( ++x & 15 ) ) {
                if ( !( ( x = y + 1 ) & 15 ) )
                    break;
                y = 15;
            }
            else if ( !--y )
                y = x, x = 1;
        }
    }
    int T; cin >> T; while ( --T >= 0 ) {
        int x, y; cin >> x >> y;
        cout << ( loses[x][y] ? "Second" : "First" ) << endl;
    }
    return 0;
}
