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
    int32_t t1, t2, n; cin >> t1 >> t2 >> n;
    BigInt T[] { { t1 }, { t2 } };
    if ( n == 1 )
        cout << T[0] << endl;
    else if ( n == 2 )
        cout << T[1] << endl;
    else {
        int T1 = 0, T2 = 1;
        for ( int i = 3; i <= n; ++i, T1 = !T1, T2 = !T2 ) {
            BigInt tmp = T[T2] * T[T2];
            T[T1] += tmp;
        }
        cout << T[T2] << endl;
    }
    return 0;
}
