#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Grid {
    const char Bomb = 'O', Empty = '.', None = 0, Exploding = 1, Ticking = 2;
    int R, C, N;
    vector< string > grid;

    void in (istream &in) {
        in >> R >> C >> N;
        grid.resize (R);
        for ( string &row : grid )
            in >> row;
    }

    void out (ostream &out) {
        for ( string &row : grid )
            out << row << endl;
        out << endl;
    }

    void debug (ostream &out) {
        for ( string &row : grid ) {
            for ( char &c : row )
                out << char( '0' + c );
            out << endl;
        }
        out << endl;
    }

    inline bool exploding ( int r, int c ) { return grid[r][c] & Exploding; }
    inline void clear ( int r, int c ) { grid[r][c] = char( unsigned(grid[r][c]) &~ Ticking ); }

    void execute () {
        prepare();
        if ( N > 200 )
            N = 200 + N % 4;
        for ( int n = 2; n <= N; ++n )
            iterate(n);
        finalize();
    }

    void iterate (int n) {
        bool filling = !( n & 1 );
        if ( filling )
            fill ();
        else
            countdown ();
    }

    void fill () {
        for ( string &row : grid )
            for ( char &c : row )
                if ( c == None )
                    c = Ticking;
    }

    void countdown ();

    void prepare () {
        for ( string &row : grid )
            for ( char &c : row )
                c = ( ( c == Bomb ) ? Exploding : None );   // first lot of bombs is first to go off
    }

    void finalize () {
        for ( string &row : grid )
            for ( char &c : row )
                c = c ? Bomb : Empty;               // reverse the process :)
    }
};

inline istream &operator>> (istream &is, Grid &grid) { grid.in(is); return is; }
inline ostream &operator<< (ostream &os, Grid &grid) { grid.out(os); return os; }

void Grid::countdown () {
    int lastRow = R - 1, lastColumn = C - 1;

    if ( R == 1 ) {
        if ( C == 1 ) {
            if ( exploding(0,0) )
                clear(0,0);
        } else {
            if ( exploding(0,0) )
                clear(0,0), clear(0,1);
            for ( int c = 1; c < lastColumn; ++c )
                if ( exploding(0,c) )
                    clear(0,c-1), clear(0,c), clear(0,c+1);
            if ( exploding(0,lastColumn) )
                clear(0,lastColumn), clear(0,lastColumn-1);
        }
    } else if ( C == 1 ) {
        if ( exploding(0,0) )
            clear(0,0), clear(1,0);
        for ( int r = 1; r < lastRow; ++r )
            if ( exploding(r,0) )
                clear(r-1,0), clear(r,0), clear(r+1,0);
        if ( exploding(lastRow,0) )
            clear(lastRow,0), clear(lastRow-1,0);
    } else {
        // top left corner
        if ( exploding(0,0) )
            clear(0,0), clear(0,1), clear(1,0);
        // rest of top row
        for ( int c = 1; c < lastColumn; ++c )
            if ( exploding(0,c) )
                clear(0,c-1), clear(0,c), clear(0,c+1), clear(1,c);
        // top right
            if ( exploding(0,lastColumn) )
                clear(0,lastColumn), clear(0,lastColumn-1), clear(1,lastColumn);
        // bulk of grid
        for ( int r = 1; r < lastRow; ++r ) {
            // first column
            if ( exploding(r,0) )
                clear(r,0), clear(r,1), clear(r-1,0), clear(r+1,0);
            for ( int c = 1; c < lastColumn; ++c )
                if ( exploding(r,c) )
                    clear(r,c-1), clear(r,c), clear(r,c+1), clear(r-1,c), clear(r+1,c);
            // last column
            if ( exploding(r,lastColumn) )
                clear(r,lastColumn), clear(r,lastColumn-1), clear(r-1,lastColumn), clear(r+1,lastColumn);
        }
        // last row
        // bottom left corner
        if ( exploding(lastRow,0) )
            clear(lastRow,0), clear(lastRow,1), clear(lastRow-1,0);
        // rest of bottom row
        for ( int c = 1; c < lastColumn; ++c )
            if ( exploding(lastRow,c) )
                clear(lastRow,c-1), clear(lastRow,c), clear(lastRow,c+1), clear(lastRow-1,c);
        // bottom right
        if ( exploding(lastRow,lastColumn) )
            clear(lastRow,lastColumn), clear(lastRow,lastColumn-1), clear(lastRow-1,lastColumn);
    }

    // actually count down here :)
    for ( string &row : grid )
        for ( char &c : row )
            c = char( unsigned(c) >> 1 );

}

int main() {
    Grid grid;
    cin >> grid;
    grid.execute();
    cout << grid;
    return 0;
}
