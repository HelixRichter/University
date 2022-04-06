#include <iostream>
#include "core.h"

using namespace std;

int main() {
    TimeDate obj;
    obj.format_str_init();

    string str;
    getline(cin, str);

    obj.parsing_timedate(str);
    cout << obj.get_time_hour() << endl;
    cout << obj.get_time_min() << endl;
    cout << obj.get_time_day() << endl;
    cout << obj.get_time_month() << endl;

    return 0;
}
