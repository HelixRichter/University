#include <iostream>
#include "core.h"

using namespace std;

int main() {
    TimeDate obj("24");
    obj.format_str_init();

    obj.parsing_date();
    cout << obj.get_time_day() << endl;
    cout << obj.get_time_month() << endl;
    cout << obj.check_date() << endl;

    return 0;
}
