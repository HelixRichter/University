#include <iostream>
#include "polynomial.h"

int main() {
    int test1[2] = {1, 2};
//    int test2[2] = {4, 4};

    polynomial TEST_1(std::begin(test1), std::end(test1));
//    polynomial TEST_2(std::begin(test2), std::end(test2));

    std::cout << TEST_1 << std::endl;

    return 0;
}
