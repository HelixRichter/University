#include "target.h"
#include <iostream>
#include <vector>

using namespace std;

target::target() {

    int temp_quantity = rand();
    for (int i = 0; i < temp_quantity; i++) {
        circle.push_back(i);
    }

}

target::target(initializer_list <int> temp) {

    for (auto i : temp) {
        circle.push_back(i);
    }

}