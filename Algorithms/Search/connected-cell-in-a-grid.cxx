#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <iterator>
//#include <utility>
using namespace std;

inline ostream &operator<< (ostream &os, vector<vector<char>> &v ) {
    for ( auto &row : v ) {
        auto i = begin(row), j = end(row);
        if ( i != j ) {
            os << int(*i);
            while (++i != j)
                os << ' ' << int(*i);
        }
        os << endl;
    }
    return os;
}
// struct cell_t { char c; };
struct location_t { int x, y; };
struct move_t { int dx, dy; };
inline location_t operator+ ( const location_t &from, const move_t &move )
        { return { from.x + move.dx, from.y + move.dy }; }

struct matrix_t {
    int n, m;
    using row_t = vector<char>;
    vector<row_t> M;
    vector< pair< location_t, int > > regions;
    inline row_t &operator[] (int n) { return M[n]; }
    inline char &operator[] (const location_t &l) { return M[l.x][l.y]; }
    inline char &cell (const location_t &l) { return (*this)[l]; }
    inline istream &read (istream &is) {
        char digit;
        for ( auto &r : M ) { for ( auto &c : r ) { is >> digit; c = digit - '0'; } }
        return is;
    }
    inline bool valid_location (location_t there) { return unsigned(there.x) < n && unsigned(there.y) < m; }
    void mark_region (location_t where, int number, int &size);
    void find_regions ();
    int biggest_region ();
    inline matrix_t (int n_, int m_) : n(n_), m(m_), M( n_, row_t(m_) ), regions() { }
};
inline istream &operator>> (istream &is, matrix_t &M) { return M.read(is); }

const move_t moves[] = {
    { -1, -1 }, { -1,  0 }, { -1, +1 },
    {  0, -1 },             {  0, +1 },
    { +1, -1 }, { +1,  0 }, { +1, +1 },
};

void matrix_t::mark_region (location_t where, int number, int &size) {
    queue<location_t> cellsToCheck;
    cellsToCheck.emplace( where );
    while (cellsToCheck.size()) {
        auto here = cellsToCheck.front(); cellsToCheck.pop();
        char &thisCell = cell(here);
        if ( thisCell <= 0 ) continue;  // already visited (or empty, but that shouldn't happen here)
        thisCell = number; ++size;      // bump the size when we mark the cell; only mark if we didn't already
        for ( auto &move : moves ) {
            location_t there = here + move;
            if (!valid_location(there))
                continue;
            if (cell(there) > 0)   // unvisited and filled
                cellsToCheck.emplace(there);
        }
    }
}

void matrix_t::find_regions () {
    char regionNumber = 0;
    for ( int r = 0; r < n; ++r ) {
        for ( int c = 0; c < m; ++c ) {
            location_t here { r, c };
            if ( cell(here) <= 0 )
                continue;
            --regionNumber;
            regions.emplace_back( here, 0 );
            mark_region( here, regionNumber, regions.back().second );
        }
    }
}

int matrix_t::biggest_region () {
    int best = 0;
    for ( auto &r : regions )
        if ( r.second > best )
            best = r.second;
    return best;
}

int main() {
    int n, m; cin >> n >> m;
    matrix_t M(n, m); cin >> M;
    M.find_regions();
    cout << M.biggest_region() << endl;
    return 0;
}
