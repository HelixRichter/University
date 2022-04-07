#include <iostream>
#include "core.h"

using namespace std;

int main() {
    TimeDate obj("11:16:23 12.18.-1875");
    obj.format_str_init();

    obj.parsing_timedate();
    obj.print();

    return 0;
}
