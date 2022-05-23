#include <iostream>
#include "polynomial.h"

int main() {
    int test1[2] = {1, 2};

    polynomial TEST_1(std::begin(test1), std::end(test1));

    std::cout << TEST_1 << std::endl;

    return 0;
}
