#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template< class T, class C = vector<T>, class I = typename C::iterator >
void replace_and_sort ( I begin, I end, T replace, T with ) {
    I place = lower_bound( begin, end, replace );
    *place = with;
    if ( with < replace && !( place == begin || with >= place[-1] ) ) {
        I newPlace = upper_bound( begin, place, with );
        rotate( newPlace, place, place + 1 );
    }
    else if ( with > replace ) {
        I nextPlace = place + 1;
        if ( nextPlace != end && with > *nextPlace ) {
            I newPlace = lower_bound( nextPlace, end, with );
            rotate( place, nextPlace, newPlace );
        }
    }
}

int main() {
    int n, d; cin >> n >> d;
    vector<int> expenditure (n); for ( auto &i : expenditure ) cin >> i;
    auto checkBegin = begin(expenditure), checkEnd = checkBegin + d, end_ = end(expenditure);
    vector<int> prior (checkBegin, checkEnd); sort (begin(prior), end(prior));
    auto middle = begin(prior) + ( d - 1 ) / 2, middle1 = middle + ( d - 1 ) % 2;
    auto twiceMedian = [&] () { return *middle + *middle1; };
    int notifications = 0;
    while ( checkEnd != end_ ) {
        int today = *checkEnd++;
        if ( today >= twiceMedian() )
            ++notifications;
        replace_and_sort( begin(prior), end(prior), *checkBegin++, today );
    }
    cout << notifications << endl;
    return 0;
}
