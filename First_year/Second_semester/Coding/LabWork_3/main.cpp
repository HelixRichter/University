#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    fraction tmp1, tmp2, tmp3;
    cout << "Enter first fraction: ";
    cin >> tmp1;

    cout << "Success!" << endl;

    cout << "Enter second fraction: ";
    cin >> tmp2;

    cout << "Success!" << endl;

//    tmp1 = tmp1 + tmp2;
//    cout << "Addition: " << tmp1 << endl;

    tmp1 += tmp2;
    cout << tmp1;

    return 0;
}
