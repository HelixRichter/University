#include <iostream>
#include "fraction.h"

using namespace std;


int main() {
    fraction tmp1, tmp2;
    cout << "[DEBUG] ENTER FRACTIONS: ";
    cin >> tmp1 >> tmp2;

    cout << "[DEBUG] FRACTION ADDING: " << tmp1 + tmp2 << endl;
    cout << "[DEBUG] FRACTION SUBTRACTING: " << tmp1 - tmp2 << endl;
    cout << "[DEBUG] FRACTION MULTIPLICATION: " << tmp1 * tmp2 << endl;
    cout << "[DEBUG] FRACTION DIVIDING: " << tmp1 / tmp2 << endl;

    return 0;
}
