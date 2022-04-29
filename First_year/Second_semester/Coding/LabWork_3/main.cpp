#include <iostream>
#include "fraction.h"

using namespace std;


int main() {
    fraction tmp1;
    cout << "Enter first fraction: ";
    cin >> tmp1;

    tmp1.simplify();
    cout << "[DEBUG] SIMPLIFIED FRACTION: " << tmp1 << endl;
//    cout << "[DEBUG] FLOATED FRACTION: " << (float) tmp1 << endl;

    return 0;
}
