
#include <iostream>
#include <cmath>
using namespace ::std;

int main (void) {
    double mealCost; int tipPercent, taxPercent;
    cin >> mealCost >> tipPercent >> taxPercent;
    cout << "The total meal cost is " << round( mealCost * ( 100 + tipPercent + taxPercent ) / 100.0 ) << " dollars.\n";
    return 0;
}
