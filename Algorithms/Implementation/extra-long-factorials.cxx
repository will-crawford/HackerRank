#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

enum { DIGITS = 9, BASE = 1000000000 };

struct BigInt {

    vector<int32_t> data;

    BigInt ( BigInt && rhs ) : data(rhs.data) { }
    BigInt ( vector<int> && data ) : data(data) { }
    BigInt & operator= ( vector<int> && rhs ) { data = move(rhs); return *this; }
    BigInt & operator= ( BigInt && rhs ) { data = move(rhs.data); return *this; }
    BigInt ( int32_t i ) : data( vector<int> { i } ) { }

    static void add ( vector<int32_t> &to, size_t toOffset, vector<int32_t> &from ) {
        if ( to.size() <= ( from.size() + toOffset ) )
            to.reserve( from.size() + toOffset + 1 );
        if ( to.size() < toOffset )
            to.resize( toOffset, 0 );
        int32_t carry = 0;
        auto lp = to.begin() + toOffset, rp = from.begin();
        while ( rp != from.end() ) {
            if ( lp == to.end() )
                to.push_back (0);
            int32_t sum = *lp + *rp + carry;
            if ( sum >= BASE )
                sum -= BASE, carry = 1;
            else
                carry = 0;
            *lp++ = sum;
            ++rp;
        }
        while ( carry ) {
            if ( lp == to.end() ) {
                to.push_back (1);
                break;
            }
            else if ( ++*lp >= BASE )
                *lp -= BASE, carry = 1;
            else
                break;
        }
    }

    BigInt & operator+= ( BigInt &rhs ) {
        add ( data, 0, rhs.data );
        return *this;
    }

    static void multiply ( vector<int32_t> &result, vector<int32_t> &lhs, vector<int32_t> &rhs ) {
        result.reserve( lhs.size() + rhs.size() + 1 );
        for ( size_t i = 0; i < rhs.size(); ++i ) {
            vector<int32_t> addend;
            int64_t factor = rhs[i];
            int64_t carry = 0;
            for ( auto multiplicand : lhs ) {
                int64_t sum = carry + factor * multiplicand;
                addend.push_back ( sum % BASE );
                carry = sum / BASE;
            }
            if ( carry )
                addend.push_back ( carry );
            add ( result, i, addend );
        }
    }

    BigInt operator* ( BigInt &rhs ) {
        vector<int32_t> result;
        multiply ( result, data, rhs.data );
        return { move (result) };
    }
};

ostream& operator<< ( ostream &os, const BigInt &bi ) {
    if ( bi.data.empty() )
        os << 0 << endl;
    else {
        auto i = bi.data.end();
        os << *--i;
        while ( i != bi.data.begin() )
            os << setw(DIGITS) << setfill('0') << *--i;
    }
    return os;
}

int main() {
    int N; cin >> N;
    BigInt Nbang (1);
    for ( int n = 2; n <= N; ++n ) {
        BigInt factor (n);
        Nbang = move( Nbang * factor );
    }
    cout << Nbang << endl;
    return 0;
}
