#include <iostream>
#include "Field3D.h"
using namespace std;

int main() {

    const Field3D test1 {3, 3, 3};
    const Field3D test2 {1, 1, 1};

    cout << "[DEBUG] FIRST VECTOR IS " << test1 << ", AND SECOND IS " << test2 << endl;
    cout << "[DEBUG] ARE FIRST AND SECOND VECTORS THE SAME? " << (test1 == test2 ? "YES" : "NO") << endl << endl;

    cout << "[DEBUG] VECTOR SUMMATION: " << test1 + test2 << endl;
    cout << "[DEBUG] VECTOR SUBTRACTION: " << test1 - test2 << endl << endl;

    cout << "[DEBUG] MULTIPLICATION BY SCALAR: " << test1 * 1 << endl;
    cout << "[DEBUG] SCALAR MULTIPLICATION: " << test1 * test2 << endl;
    cout << "[DEBUG] VECTOR MULTIPLICATION: " << test1.vector_product(test2) << endl << endl;

    cout << "[DEBUG] DISTANCE BETWEEN FIRST AND SECOND VECTORS: " << test1.distance(test2) << endl;
    cout << "[DEBUG] VECTOR'S VALUE: " << test1.vector_value() << endl;

    return 0;
}
