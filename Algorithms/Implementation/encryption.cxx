#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string message; getline (cin, message);
    int length = message.length(), rows = sqrt (length), columns = rows;
    if ( rows * columns < length )
        ++columns;
    if ( rows * columns < length )
        ++rows;
    message.resize ( rows * columns, ' ' );
    cerr << '|' << message << '|' << endl;
    for ( int i = 0; i < columns; ++i ) {
        cerr << "i = " << i << endl;
        for ( int j = i; j < length; j += columns ) {
            cerr << "j = " << j << endl;
            cout << message[j];
        }
        cout << ' ';
    }
    cout << endl;
    return 0;
}
