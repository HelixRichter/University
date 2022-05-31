#include <iostream>
#include "live.h"

int main() {

    live example {4, 4};
    std::cout << example << std::endl << std::endl;

    example.cycle();
    std::cout << example << std::endl << std::endl;

    return 0;

}
