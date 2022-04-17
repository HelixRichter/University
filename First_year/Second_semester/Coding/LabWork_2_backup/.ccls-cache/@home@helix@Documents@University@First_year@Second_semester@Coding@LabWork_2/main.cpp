#include <iostream>
#include "core.h"

using namespace std;

int main() {
    TimeDate obj("12:17:24");
    obj.format_str_init();
    obj.parsing_time();

    obj.print();
    return 0;
}
