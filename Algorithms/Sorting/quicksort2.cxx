#include <bits/stdc++.h>
using namespace std;

inline ostream &operator<< (ostream &os, vector<int> &v) {
    auto i = begin(v), j = end(v);
    if ( i != j ) {
        os << *i;
        while ( ++i != j )
            os << ' ' << *i;
    }
    return os;
}

void quickSort(vector <int> &arr) {
    vector<int> left, equal, right;
    int p = arr[0];
    for ( auto i : arr )
        ( i < p ? left : i == p ? equal : right ).emplace_back (i);
    if ( left.size() > 1 )
        quickSort(left);
    if ( right.size() > 1 )
        quickSort(right);
    copy(
        begin(right), end(right), copy(
            begin(equal), end(equal), copy(
                begin(left), end(left), begin(arr)
            )
        )
    );
    cout << arr << endl;
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
