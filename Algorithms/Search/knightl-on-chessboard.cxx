#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

ostream & operator<< ( ostream &os, const vector<vector<int>> &v ) {
    for ( auto r = begin(v); r != end(v); ++r ) {
        auto c = begin(*r);
        os << *c;
        while ( ++c != end(*r) )
            os << ' ' << *c;
        os << endl;
    }
    return os;
}

struct square_t { int x, y; };
struct move_t { int dx, dy; };
square_t operator+ ( const square_t &s, const move_t &m ) { return square_t { s.x + m.dx, s.y + m.dy }; }

struct board_t {
    int n;
    vector<vector<int>> board;
    board_t (int n) : n(n), board(n, vector<int>(n, -1)) { }
    int  operator[] (const square_t &square) const { return board[ square.x ][ square.y ]; }
    int& operator[] (const square_t &square)       { return board[ square.x ][ square.y ]; }
    const vector<int>& operator[] (int x) const { return board[x]; }
          vector<int>& operator[] (int x)       { return board[x]; }
    int back() const { return board.back().back(); }
};
using queue_t = queue<square_t>;

inline bool valid ( int i, int n ) { return unsigned(i) < n; }
inline bool valid ( const square_t &square, int n ) { return valid(square.x, n) && valid(square.y, n); }

int moves ( int n, int i, int j ) {
    board_t board (n);
    vector<move_t> moves {
        { i, j }, { i, -j }, { -i, -j }, { -i, j },
        { j, i }, { j, -i }, { -j, -i }, { -j, i },
    };
    square_t start { 0, 0 };
    board[start] = 0;
    queue_t squares; squares.push ( start );
    while (squares.size()) {
        square_t square = squares.front(); squares.pop();
        int depth = board[square] + 1;
        for ( auto &move : moves ) {
            square_t newSquare = square + move;
            if ( valid(newSquare, n) ) {
                int &s = board[newSquare];
                if ( s < 0 ) {
                    s = depth;
                    squares.push(newSquare);
                }
            }
        }
    }
    return board.back();
}

vector<vector<int>> moves ( int n ) {
    vector< vector<int> > result ( n - 1, vector<int> (n - 1) );
    for ( int i = 0; i < n - 1; ++i )
        for ( int j = i; j < n - 1; ++j )
            result[i][j] = result[j][i] = moves(n, i + 1, j + 1);
    return result;
}

int main() {
    int n; cin >> n;
    cout << moves(n) << endl;
    return 0;
}
