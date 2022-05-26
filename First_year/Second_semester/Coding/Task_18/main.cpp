#include <iostream>
#include "live.h"

int main() {

    live example {6, 4};
    std::cout << example << std::endl << std::endl;

    live test = example;
    std::cout << test << std::endl;



    return 0;

}
