#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int n; cin >> n;
    string name, dummy; int t; unordered_map<string, int> book;
    while ( --n >= 0 ) {
        cin >> name >> t; getline (cin, dummy);
        book[name] = t;
    }
    while ( getline(cin, name) ) {
        auto result = book.find(name);
        if ( result != book.end() )
            cout << name << '=' << result->second << endl;
        else
            cout << "Not found" << endl;
    }
    return 0;
}
